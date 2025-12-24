from time import strftime, gmtime, sleep
import sys

class Command:
    def __init__(self, cmd_arg):
        self.cmd_arg
        
    def cmd(self):
        pass

class Exit(Command):
    def __init__(self):
        pass
    
    def cmd(self):
        print("Saliendo de Akon Shell System...")
        sleep(0.5)
        sys.exit()
        
class ShowTime(Command):
    def __init__(self):
        self.timestamp = strftime("%Y-%m-%d %H:%M:%S", gmtime())
        
    def cmd(self):
        print("---AKON SHELL SYSTEM---")
        print(self.timestamp)    
        
class Echo(Command):
    def __init__(self, cmd_args: list[str]) -> None:
        self.cmd_args = cmd_args
        
    def cmd(self):
        string = ""
        for arg in self.cmd_args:
            string = string + arg + " "
            
        print(string)

class Interprete:
    def interpretar(self, line) -> None:
        position = 0
        length_line = len(line)
        cmd = line.split(" ")[0]
        args = line.split(" ")[1:]
        
        if cmd == "echo":
            echo = Echo(args)
            echo.cmd()
        elif cmd == "showtime":
            showtime = ShowTime()
            showtime.cmd()
        elif cmd == "exit":
            exit = Exit()
            exit.cmd()
        else:
            print(f"el comando {cmd} no existe.")
            return

if __name__ == "__main__":
    cmd_interprete = Interprete()
    while True:
        cmd_interprete.interpretar(input(">> "))
        