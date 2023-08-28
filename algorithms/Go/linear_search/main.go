package main

import "fmt"

func add(x int, y int) int {
    return x + y
}

func SwapString(x string, y string) (string, string) {
    return y, x
}

func main() {
    var i int
    var b bool = false

    fmt.Println("Hello, World!!")

    a := add(2, 3)

    fmt.Println(a)

    x, y := SwapString("World", "Hello,")

    fmt.Println(x, y)

    if b == true{
        fmt.Println("b is true")
    } else {
        fmt.Println("b is flase")
    }

    for j := 0; j < 10; j++ {
        fmt.Println(j)
    }

    i = 0;
    for i < 10 {
        fmt.Println(i)
        i++
    }
}
