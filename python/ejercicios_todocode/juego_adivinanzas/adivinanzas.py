from random import randint

random_num = randint(1, 100)
score = 0
stop_game = False

def main() -> int:
    global random_num
    global score
    global stop_game
    
    print("---JUEGO BASICO DE ADIVINANZAS DE NUMEROS EN PYTHON---")
    print("\nRules: las reglas son simples, tienes que adivinar un numero del 1 al 100 y ganas,"
           "luego ves tu puntaje de cuantos intentos te tomo.")
    
    while not stop_game:
        player_num = int(input("\nDigita un numero -> "))
        score += 1
        
        if player_num < random_num:
            print("\nMas arriba.")
        elif player_num > random_num:
            print("\nMas abajo.")
        else:
            print(f"\nGanaste!, te tomo {score} intentos.")
            stop_game = game_again()
    
    return 0


def game_again() -> bool:
    global random_num
    global score
    global stop_game
    again = input("Quieres volver a intentarlo y sacar un mejor puntaje?(S/N): ").lower()
    
    while True:
        if again == 's':
            random_num = randint(1, 100)
            score = 0
            return False
        elif again == 'n':
            print("FIN DEL JUEGO")
            print("SALIENDO DEL PROGRAMA...")
            return True
        else:
            again = input("Opcion invlida, elige S o N para seguir con el juego o no: ").lower()
            

if __name__ == "__main__":
    main()
    