package main

import (
	"fmt"
)

func main(){
	s:="hello world!!"
	fmt.Println("hello world!!")
	fmt.Println("hello " +
		"world!!")
	fmt.Println(s)

	var a int=1		//a:=1或者var a=1   声明一个变量
	fmt.Println(a)
	var(
		a1 int =1
		a2 int =2
	)		//多个变量声明
	fmt.Println(a1+a2)
	const Name="张俊涛"
	const Year=2022			//定义常量
	fmt.Println(Name,Year)
	const(
		a3=iota
		b1
		c1
		d1
	)
	fmt.Println(a3,b1,c1,d1)
	fmt.Println(sum(a1,a2))//调用函数

	var arr=[...]int{1,2,3,4,5}
	for i:=1;i<=5;i++{
		fmt.Println(arr[i-1])
	}

	slice:=arr[0:3]		//切片
	fmt.Println(slice)

	var slice2=make([]int,5,10)		//动态切片
	fmt.Println("slice2 len is :",len(slice2))
	slice2=arr[0:2]
	fmt.Println(slice2)

	var srcSlice1,srcSlice2=[]int{1,2},[]int{4,5}
	var desSlice[]int
	desSlice = append (srcSlice1,3)
	fmt.Println(desSlice)
	desSlice = append (desSlice,srcSlice2...)
	fmt.Println(desSlice)

	nums := []int{1,2,3,4,5,6}
	for i:=0;i<len(nums);i++{
		fmt.Println()
	}
}

func sum(a int,b int)int{
	return a+b
}						//定义和
