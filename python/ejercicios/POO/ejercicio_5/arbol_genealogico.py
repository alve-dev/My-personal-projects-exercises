"""
Ejercicio 5 — Árbol genealógico

Objetivo: aprender a construir estructuras tipo AST.

Requerimiento:

    • Clase Person: nombre, edad.
    • Cada persona puede tener padre, madre, y una lista de hijos.
    • Método para imprimir el árbol completo de descendencia.

Expectativas:

    • Recursión controlada
    • Evitar loops infinitos
    • Objetos referenciándose entre sí

Tiempo: 1-2 horas
"""

class Person:
    FEMALE = ["f", "female", "woman"]
    MALE = ["m", "male", "man"]
    
    def __init__(self, name:str, age:int, gender:str):
        self.name = name
        self.age = age
        self.gender = gender.lower()
        self.father = None
        self.mother = None
        self.children = []
        
    def add_child(self, person):
        self.children.append(person)
        
        if self.gender in self.MALE:
            person.father = self
            
        elif self.gender in self.FEMALE:
            person.mother = self
        
        
    def print_immediate_family(self):
        if self.father == None:
            print(f"Father: None | ", end="")
        else:
            print(f"Father: {self.father.name} ({self.father.age}) | ", end="")
            
        if self.mother == None:
            print("Mother: None")
        else:  
            print(f"Mother: {self.mother.name} ({self.mother.age})")
        
        if len(self.children) >= 1:
            print("Childs: ", end="")
            for child in self.children:
                print(f"{child.name} ({child.age})", end="")
                if child != self.children[-1]:
                    print(", ", end="")
                else:
                    print("")
                  
    def print_descendants(self, person=None, ident=0):
        if person is None:
            print(f"{self.name} ({self.age})")
            children = self.children
        else:
            children = person.children
            
        if len(children) >= 1:
            for child in children:
                if len(child.children) < 1:              
                    if child == children[-1]:
                        print("  "*ident, f"└──{child.name} ({child.age})")
                    else:
                        print("  "*ident, f"├──{child.name} ({child.age})", end="\n │")     
                else:
                    print(f" ├──{child.name} ({child.age})", end="\n │")
                    self.print_descendants(child, ident+1)  
                    
    def print_ancestors(self, person=None, ident=0):
        if person == None:
            print(f"{self.name} ({self.age})")
            parents = [self.father, self.mother]
        else:
            parents = [person.father, person.mother]
        
        for parent in parents:
            if parent == None:
                continue
            
            if parent.father == None and parent.mother == None:
                print(" "*ident, f"└──{parent.name} ({parent.age})")
            else:
                print(f" └──{parent.name} ({parent.age})")
                self.print_ancestors(parent, ident+1)
    
    def get_generation(self, generation=0, person=None):
        generation_list = []
        
        if generation == 0:
            return [self]    
        if person == None:
            children = self.children
        else:
            children = person.children
        if len(children) < 1:
            return []
        if generation == 1:
            return children
        if generation > 1:
            for child in children:
                generation_list.extend(self.get_generation(generation-1, child))
                
            return generation_list
    
    def find_person(self, name:str, current_person=None):
        
        if current_person is None:
            current_person = self
        
        if current_person.name == name:
            return current_person
        
        for child in current_person.children:
            resultado = self.find_person(name, child)
            if resultado != None:
                return resultado
    
        return None
                                       
        
def main():
    # ==== Crear personas ====
    # Generación 1 (Bisabuelos)
    bisabuelo = Person("Don Ernesto", 98, "m")

    # Generación 2 (Abuelos)
    abuelo1 = Person("Carlos", 78, "m")
    abuela1 = Person("Marta", 75, "f")
    
    abuelo2 = Person("Jorge", 80, "m")
    abuela2 = Person("Elena", 77, "f")

    # Generación 3 (Padres y tíos)
    padre = Person("Luis", 50, "m")
    madre = Person("Patricia", 48, "f")

    tio1 = Person("Ricardo", 53, "m")
    tia1 = Person("Lucía", 51, "f")

    tio2 = Person("Fernando", 55, "m")
    tia2 = Person("Alicia", 54, "f")

    # Generación 4 (Hijos)
    hijo1 = Person("Alejandro", 20, "m")
    hijo2 = Person("Sofía", 17, "f")
    hijo3 = Person("Mateo", 14, "f")

    primos1 = Person("Camila", 22, "f")
    primos2 = Person("Daniel", 18, "m")
    primos3 = Person("Mariana", 16, "f")
    
    primos4 = Person("Valentina", 23, "f")
    primos5 = Person("Samuel", 19, "m")

    # ==== Armar árbol familiar ====

    # Bisabuelos → Abuelos
    bisabuelo.add_child(abuelo1)
    bisabuelo.add_child(abuelo2)

    # Abuelos → Padres y tíos
    abuelo1.add_child(padre)
    abuelo1.add_child(tio1)
    abuelo2.add_child(madre)
    abuelo2.add_child(tio2)

    # Padres → Hijos
    padre.add_child(hijo1)
    padre.add_child(hijo2)
    padre.add_child(hijo3)

    madre.add_child(hijo1)  # si manejas bi-parental
    madre.add_child(hijo2)
    madre.add_child(hijo3)

    # Tío1 → primos
    tio1.add_child(primos1)
    tio1.add_child(primos2)
    tio1.add_child(primos3)

    # Tío2 → primos
    tio2.add_child(primos4)
    tio2.add_child(primos5)

    # ==== Probar impresión del árbol ====
    print("\n=== ÁRBOL FAMILIAR COMPLETO ===")
    print(bisabuelo.print_descendants())

    print("\n=== SUBÁRBOL DE LOS ABUELOS ===")
    print(abuelo1.print_descendants())

    print("\n=== FAMILIA DEL PADRE ===")
    print(padre.print_descendants())

    print("\n=== FAMILIA DEL TÍO 2 ===")
    print(tio2.print_descendants())


if __name__ == "__main__":
    main()
