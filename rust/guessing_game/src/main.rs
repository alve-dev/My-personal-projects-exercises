use std::io;
use rand::Rng;

fn main() {
    let random_num = rand::thread_rng().gen_range(1..101);
    let mut intentos = 0;

    println!("--ADIVINA EL NUMERO EN RUST--\n");
    loop {
        let mut guess = String::new();

        println!("Digita un numero por favor:");
        io::stdin()
            .read_line(&mut guess)
            .expect("Failed to read line");

        let guess: u32 = match guess.trim().parse() {
            Ok(num) => num,
            Err(_) => continue,
        };

        intentos += 1;

        if guess > random_num {
            println!("Intenta con un numero mas pequeño.\n");
        } else if guess < random_num {
            println!("\nIntenta con un numero mas grande.\n");
        } else {
            println!("Has ganado!!\n");
            break;
        }
    }

    println!("Tus intentos: {intentos}");
}

