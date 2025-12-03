"""
Ejercicio 4 — Sistema de logs estilo mini-framework

Objetivo: múltiples clases interactuando con responsabilidad clara.

Requerimiento profesional:
    • Clase LogMessage: nivel (INFO, WARN, ERROR), timestamp, texto.
    • Clase Logger: recibe mensajes y los guarda.
    • Clase LogFormatter: formatea mensajes al imprimirlos.
    
Expectativas:
    • No mezclar formato con almacenamiento.
    • Métodos pequeños, ordenados.
    
Tiempo: 1-1.5 horas
"""
from time import gmtime, strftime

class LogMessage:
    def __init__(self, level:str, text:str):
        self.timestamp = strftime("%Y-%m-%d %H:%M:%S", gmtime())
        self.level = level
        self.text = text
        
class FileFormatter:
    def format(self, log_message: LogMessage):
        return f"[{log_message.timestamp}] [{log_message.level}] {log_message.text}"
    
class ColorConsoleFormatter:
    COLORS = {
        "DEBUG": "\033[96m",
        "INFO": "\033[92m",
        "WARN": "\033[93m",
        "ERROR": "\033[91m"
        }
    
    RESET = "\033[0m"

    def format(self, log_message: LogMessage):
        color = self.COLORS.get(log_message.level)
        return f"{color}[{log_message.timestamp}] [{log_message.level}] {log_message.text}"
    
           
class Logger:
    def __init__(self, min_level="INFO"):
        self.messages_list = []
        self.min_level = min_level
        self.levels = {"DEBUG":0, "INFO":1, "WARN":2, "ERROR":3}
        self.timestamp_file = strftime("%Y-%m-%d", gmtime())
    
    def set_level(self, new_level):
        self.min_level = new_level
        
    def log(self, level:str, text:str):
        if self.levels[level] >= self.levels[self.min_level]:
            log_message = LogMessage(level, text)
            self.messages_list.append(log_message)
    
    def write_to_files(self, formatter:FileFormatter):
        with open(f"{self.timestamp_file}-application.log", "a") as application_log:
            
            with open(f"{self.timestamp_file}-errors", "a") as errors_log:
                for msg in self.messages_list:
                    
                    application_log.write(formatter.format(msg) + "\n")
                    if self.levels[msg.level] >= self.levels["WARN"]:
                        errors_log.write(formatter.format(msg) + "\n")
        
        self.messages_list.clear()
        
    def print_logs(self, formatter:ColorConsoleFormatter | FileFormatter):
        for msg in self.messages_list:
            print(formatter.format(msg))
        
        

if __name__ == "__main__":
    logger = Logger(min_level="INFO")
    file_fmt = FileFormatter()
    console_fmt = ColorConsoleFormatter()

    logger.log("INFO", "Servidor iniciado")
    logger.log("WARN", "Memoria al 92%")
    logger.log("ERROR", "Conexión perdida con Redis")
    logger.log("DEBUG", "Esto no entra")
    logger.log("WARN", "Otro warning para que veas duplicado")

    print("=== CONSOLA ===")
    logger.print_logs(console_fmt)

    print("\n=== ESCRIBIENDO A DISCO... ===")
    logger.write_to_files(file_fmt)

    print("¡Listo! Revisá la carpeta → dos archivos con fecha de hoy creados mágicamente")