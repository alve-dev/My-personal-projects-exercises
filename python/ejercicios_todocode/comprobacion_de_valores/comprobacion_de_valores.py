# Realizar un programa que permita cargar 15 numeros en un vector.
# Una vez cargados, se necesita que el programa cuente e informe por pantalla cuantas veces se cargo el numero 3
import random

def main() -> int:
    numbers: list[int] = []
    cont_three: int = 0

    for i in range(15):
        numbers.append(random.randint(1, 15))

    for number in numbers:
        if number == 3:
            cont_three += 1
    
    print(f"El numeros 3 se cargo {cont_three} veces en el array.")
    print(numbers)
    return 0

if __name__ == "__main__":
    main()