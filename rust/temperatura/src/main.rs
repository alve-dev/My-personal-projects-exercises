fn main() {
    let farenheit = 68.0;
    let celsius = farenheit_to_celsius(farenheit);

    println!("Farenheit: {farenheit}");
    println!("Celsius: {celsius}");
}

fn farenheit_to_celsius(farenheit: f64) -> f64 { return (farenheit - 32.0) / 1.8; }

/*Akorn version

func main() -> int
{
    let farenheit = 68.0;
    let celsius = farenheit_to_celcius(farenheit);

    write("Farenheit:", farenheit);
    write("Celsius:", celsius);

    return 0;

}

func farenheit_to_celsius(float farenheit) -> float => (farenheit - 32.0) / 1.8;
*/