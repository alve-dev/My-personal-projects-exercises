from json import dump, load



class Task:
    def __init__(self, descripcion:str, ):
        self.descripcion = descripcion
        self.estado = "pendiente"
        
    def __str__(self):
        return f"Tarea:{self.descripcion}: Estado:{self.estado}"
    
    def __repr__(self):
        return f"<descripcion={self.descripcion} estado={self.descripcion}>"
    
    def completar(self):
        self.estado = "completado"

stop_program = False
lista_tareas = ["default_value"]
   
def main() -> int:
    global stop_program
    load_json()
    while not stop_program:
        print("\n\t---GtbPy(Gestor de Tareas Basico en PYthon)---\n")
        print("1.Añadir Tarea.")
        print("2.Ver Tarea.")
        print("3.Eliminar Tarea..")
        print("4.Completar Tarea.")
        print("5.Salir.")
        stop_program = opcs()
        
    
    return 0

def opcs() -> bool:
    global stop_program
    opc = input("\nOpcion -> ")
    
    while True:
        
        if opc == '1':
            add_task()
            print("Tarea agregada.")
            break
        elif opc == '2':
            see_task()
            break
        elif opc == '3':
            remove_task()
            print("Tarea eliminada.")
            break
        elif opc == '4':
            complete_task()
            break
        elif opc == '5':
            print("Saliendo de programa...")
            return True    
        else:
            opc = input("Opcion no valida, vuelve a intentarlo.")
        
    return False

def save_json():
    global lista_tareas
    with open("tasks_saved.json", "w") as saved:
        dump(lista_tareas, saved)
        
def load_json():
    global lista_tareas
    try:
        with open("tasks_saved.json", "r") as loads:
            lista_tareas = load(loads)
    except FileNotFoundError:
        save_json()
        
        
def add_task():
    global lista_tareas
    new_task = Task(input("\nTarea: "))
    lista_tareas.append(new_task)
    save_json()
    
def complete_task():
    see_task()
    index_tarea = int(input("/nElige que tarea marcar como completada, eligiendo su numero -> "))
    global lista_tareas
    tarea:Task = lista_tareas[index_tarea-1]
    tarea.completar()
    
    
def see_task():
    global lista_tareas
    len_list = len(lista_tareas)
    print("\n")
    if len_list > 0:
        for i in range(len_list):
            tarea:Task = lista_tareas[i]
            print(f"{i+1}.{tarea.descripcion}, Estado:{tarea.estado}")
    else:
        print("Vacio...")    

def remove_task():
    see_task()
    remove = int(input("Elige cual tarea eliminar, eligiendo su numero -> "))
    global lista_tareas
    lista_tareas.pop(remove-1)


if __name__ == "__main__":
    main()