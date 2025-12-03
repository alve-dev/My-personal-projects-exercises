"""Ejercicio 1 — Contador simple

    Objetivo: dominar atributos, métodos y __str__.

    Requerimiento profesional:

        * Crear una clase Counter con:

            * método increment()

            * método decrement()

            * método reset()

        * Debe poder imprimirse (__str__) mostrando: "Counter(value=10)".

    Lo que evaluamos:

        * Uso correcto de self

        * Estados internos simples

    Tiempo estimado: 10–20 min
"""

class Counter(object):
    #Atributos
    def __init__(self, value: int = 0):
        self.value_inmutable = value    #porque?, para que cuando se llame a reset se resetee con el valor dado si se dio
        self.value = value
        
        
    #Metodos
    def increment(self):
        self.value += 1
    
    def decrement(self):
        self.value -= 1
    
    def reset(self):
        self.value = self.value_inmutable
    
    def __str__(self):
        return f"Counter({self.value})"

counter = Counter()

print(counter)
counter.increment()
print(counter)
counter.increment()
counter.increment()
counter.increment()
print(counter)
counter.decrement()
print(counter)
counter.decrement()
counter.decrement()
print(counter)
counter.reset()
print(counter)