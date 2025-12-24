#Programa que pida un numero maximo, y que luego muestre en terminal desde 1 hasta ese numero maximo

def main():
    n: int = int(input("Digita un valor: "))
    for i in range(1, n+1):
        print(i)
        
if __name__ == "__main__":
    main()