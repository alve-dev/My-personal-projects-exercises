// Fibonacci en rust

fn main() {
    let n = 10;
    let mut count = 0;
    let mut back_1 = 0;
    let mut current = 1;
    
    print!("{} {} ", back_1, current);

    while count < n - 2 {
        let next = back_1 + current;
        print!("{} ", next);
        back_1 = current;
        current = next;
        count += 1;
    }
    println!("");
}

/*Akorn Version

func main() -> int
{
    let n = 10;
    var count = 0;
    var back_1 = 0;
    var current = 0;
    var next = back_1 + current;

    write("0 1 ", end='');
    while count < n
    {
        write(f"\(next)", end=' ');
        back_1 = current;
        current = next;
        next = back_1 + current;
        count += 1;
    }

    return 0;
}
*/

