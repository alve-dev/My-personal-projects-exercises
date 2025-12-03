class Task:
    def __init__(self, descripcion:str):
        self.descripcion = descripcion
        self.estado = "pendiente"
        
    def __str__(self):
        return f"Tarea:{self.descripcion}: Estado:{self.estado}"
    
    def __repr__(self):
        return f"<descripcion={self.descripcion} estado={self.descripcion}>"
    
    def completar(self):
        self.estado = "completado"