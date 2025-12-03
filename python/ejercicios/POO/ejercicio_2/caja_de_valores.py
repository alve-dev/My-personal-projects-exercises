"""
Ejercicio 2 — Caja de valores con validación

    * Objetivo: practicas encapsulación + validación.

    * Requerimiento profesional:

        * Clase ValueBox

        * almacena solo ints

        * lanza excepción si guardas tipos distintos

        * método get(), set(value), clear()

    * Expectativa profesional:

    * Uso correcto de errores personalizados (ej: TypeError)

    * Nada de lógica floja

    * Tiempo estimado: 20–30 min
"""

class ValueBox:
    def __init__(self):
        self.int_box = []
    
    #Metodos
    def get(self) -> list:
        """Retorna una lista con la caja de ints

        Returns:
            list: caja de ints
        """
        return self.int_box
    
    def verificar_tipo(self, value):
        if not isinstance(value, int):
            raise TypeError("Solo se permiten enteros")
            
        
    def set(self, value):
        """Agrega valores int a la caja

        Args:
            value (_int_): Valor a guardar
        """
        
        self.verificar_tipo(value)
        self.int_box.append(value)
         
    
    def clear(self):
        self.int_box.clear()

box = ValueBox()

box.set("Hola")
print(box.get())




