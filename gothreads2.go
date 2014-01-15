package main

import (
    . "fmt"
    . "runtime"
    . "time"
)

var i = 0

func incrementor(ic chan int){
    for x := 0; x < 1000000; x++ {
        ic <- 1
        i++
        <- ic
    }
}

func decrementor(ic chan int){
    for x := 0; x < 1000000; x++ {
        ic <- 1
        i--
        <- ic
    }
}

func main() {
    
    ic := make(chan int, 1)
    
    GOMAXPROCS(NumCPU())        
    go incrementor(ic)                  
    go decrementor(ic)
    
    Sleep(1000*Millisecond)
    Println("Done:", i)
    
}
