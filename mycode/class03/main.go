package main

import (
	"fmt"
	"sync"
	"time"
)

var (
	wg sync.WaitGroup	//小本本
	x int
    mu sync.Mutex		//互斥锁,控制共享资源
	// 类似于上厕所锁门，上一个人出来，下一个人才能进去
)


func main(){
	//F1()
	//F2()
	//F30()
	//F31()
	//F40()
	//F41()
	//F50()
}

func F50(){
	c := make(chan int )
	quit := make(chan int)
	go func() {
		for i := 0; i < 10 ; i++ {
			// 接受通道c传来的值，并打印到控制台
			fmt.Println(<-c)
		}
		// 当协程执行完上述操作后，向quit发送数据
		quit <- 0
	}()
	fibonacci(c, quit)
}//测试select

func fibonacci(ch,quit chan int){
	x,y:=0,1
	for{
		select{
		case ch<-x:
			x,y=y,x+y
		case <-quit:
			fmt.Println("quit")
			return
		}
	}

}//selec监控

func F41(){
	send := make(chan int)
	go counter(send)
	squarer(send)
}//测试单方向的channel

func counter(out chan<-int){
	for x := 0; x < 100; x++ {
		out <- x
	}
	close(out)
}// 这里的out只能进行发送操作

func squarer(in <-chan int){
	for v := range in {
		fmt.Println(v)
		}
}// 这里的in只能进行接收操作

func F40(){
	c:=make(chan int,10)
	go feibo(cap(c),c)//调用feibo给c的缓存赋值

	for i:=range c{
		fmt.Println(i)
	}		//遍历c
}//Rang&close

func feibo(n int,c chan int){
	x,y:=1,1
	for i:=0;i<n;i++{
		c<-x
		x,y=y, y+x//交换变量的简易操作
	}
	close(c)
	//防止死锁
}//赋值feibo

func F31(){
	var channel = make(chan int)	//不带缓存的管道
	send:=6666
	var receive int
	// 关键字go后跟的是需要被并发执行的代码块，它由一个匿名函数代表
	go func(){
		channel<-send	//传send的值进管道
		fmt.Println("数据已传输")
	}()
	receive=<-channel	//receive接收channel的值
	time.Sleep(1*time.Second)
	fmt.Println(receive)
}//改进F30
//带了缓存的管道相当于里面有一个元素队列
//而不带缓存或超过缓存大小时的数据传输操作都会导致堵塞
//而无法执行传输语句后后面的语句
//ch<-会比<-先发生

func F30(){
	var channel = make(chan int)	//不带缓存的管道
	send:=6666
	// 关键字go后跟的是需要被并发执行的代码块，它由一个匿名函数代表
	go func(){
		channel<-send
		fmt.Println("数据已传输")
	}()
	time.Sleep(1*time.Second)
}//一个基于无缓存Channels的发送操作将导致发送者goroutine阻塞
//直到另一个goroutine在相同的Channels上执行接收操作，

func F2() {
	wg.Add(2)
	go add()
	go add()
	wg.Wait()
	fmt.Println(x)
}	//互斥锁测试

func add(){
	for i:=0;i<50000;i++{
		mu.Lock()
		x++
		mu.Unlock()
	}
	wg.Done()
}

func F1(){
	wg.Add(2) 		//记录协程个数
	go bar("茄子")
	go bar("韭菜")
	bar("鸡腿")
	wg.Wait()		//等待子协程执行完毕
	fmt.Println("over@!")
}	//主子协程测试

func bar(dishes string){
	for i:=0;i<=5;i++{
		fmt.Printf("正在烤"+dishes+",熟度为:%d分熟\n",i*2)
		time.Sleep(time.Second)
	}
	fmt.Println(dishes+"烤好了")
	time.Sleep(2*time.Second)
	wg.Done()		//协程个数-1
}


