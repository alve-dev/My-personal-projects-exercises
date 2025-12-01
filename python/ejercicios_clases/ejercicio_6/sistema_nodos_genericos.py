"""
Ejercicio 6 — Sistema de nodos genéricos

Objetivo: fortalecer habilidades directamente aplicables a ASTs sin ser un parser.

Requerimiento:
    • Clase base Node
    
    • Subclases:
        ◦ ValueNode (contiene valor literal)
        ◦ UnaryNode (un operador y un hijo)
        ◦ BinaryNode (operador, left, right)
        
    • Debe tener:
        ◦ método evaluate()
        ◦ método pretty_print() (visualización del árbol)

Expectativa profesional:

    • Polimorfismo limpio
    • Jerarquía coherente
    • Nada de condicionales gigantes

Tiempo: 2-3 horas
"""

class Node:
    def __repr__(self):
        return f"{self.__class__.__name__}"
    
    def evaluate(self):
        raise NotImplementedError

    def pretty_print(self):
        return str(self.evaluate())

    
class ValueNode(Node):
    def __init__(self, value):
        self.value = value
    
    def __repr__(self):
        return f"<{self.__class__.__name__} value={self.value}>"
     
    def evaluate(self) -> int|float:
        if self.value is None:
            raise ValueError("ValueError: Se esperaba un valor valido")
        return self.value

    def pretty_print(self):
        return str(self.value)


class UnaryNode(Node):
    def __init__(self, operator:str, node:Node):
        self.operator = operator
        self.node = node
    
    def __repr__(self):
        return f"<{self.__class__.__name__} operator={self.operator}>"
 
    def evaluate(self) -> int|float:
        if self.operator != '-':
            raise ValueError("UnaryError: Se esperaba un operador valido.")
        return -self.node.evaluate()
    
    def pretty_print(self):
        child_str = self.node.pretty_print()
        if isinstance(self.node, (BinaryNode, UnaryNode)):
            child_str = f"({child_str})"
        return f"{self.operator}{child_str}"


class BinaryNode(Node):
    def __init__(self, operator:str, left:Node, right:Node):
        self.operator = operator
        self.left = left
        self.right = right
    
    def __repr__(self):
        return f"<{self.__class__.__name__} operator={self.operator} left={self.left} right={self.right}>"
        
    def evaluate(self) -> int|float:
        left = self.left.evaluate()
        right = self.right.evaluate()
        operator = self.operator
        
        if operator == '+':
            return left + right
        elif operator == '-':
            return left - right
        elif operator == '*':
            return left * right
        elif operator == '/':
            if right == 0:
                raise ZeroDivisionError("No se puede dividir por cero")
            return left / right
        else:
            raise ValueError("Se esperaba operador valido(+, -, * o /)")
        
    def pretty_print(self):
        left_str = self.left.pretty_print()
        right_str = self.right.pretty_print()
        
        if isinstance(self.left, BinaryNode) and self.operator in ['*', '/'] and self.left.operator in ['+', '-']:
             left_str = f"({left_str})"
             
        if isinstance(self.right, BinaryNode) and self.operator in ['*', '/'] and self.right.operator in ['+', '-']:
             right_str = f"({right_str})"

        return f"{left_str} {self.operator} {right_str}"
       
       
        

if __name__ == "__main__":
    print("=" * 50)
    print("        ÁRBOLES DE PRUEBA - MODO DIOS")
    print("=" * 50 + "\n")

    # 10 + (-5 * 3)   →  10 + (-15) = -5
    tree1 = BinaryNode(
        "+",
        ValueNode(10),
        BinaryNode("*", UnaryNode("-", ValueNode(5)), ValueNode(3))
    )
    print("1) 10 + (-5 * 3)")
    tree1.pretty_print()
    print(f"   → Evaluación: {tree1.evaluate()}\n")

    # (20 - 8) / 4   →  12 / 4 = 3.0
    tree2 = BinaryNode(
        "/",
        BinaryNode("-", ValueNode(20), ValueNode(8)),
        ValueNode(4)
    )
    print("2) (20 - 8) / 4")
    tree2.pretty_print()
    print(f"   → Evaluación: {tree2.evaluate()}\n")

    # 2 + 3 * 4 - -10   →  2 + 12 + 10 = 24
    tree3 = BinaryNode(
        "-",
        BinaryNode("+", ValueNode(2), BinaryNode("*", ValueNode(3), ValueNode(4))),
        UnaryNode("-", ValueNode(10))
    )
    print("3) 2 + 3 * 4 - -10")
    tree3.pretty_print()
    print(f"   → Evaluación: {tree3.evaluate()}\n")

    # Bonus del infierno: división por cero
    try:
        bad = BinaryNode("/", ValueNode(10), ValueNode(0))
        bad.evaluate()
    except ZeroDivisionError as e:
        print(f"¡Capturado correctamente! → {e}")
