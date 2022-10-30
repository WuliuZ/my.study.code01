package main

import "fmt"
type Student struct{
	Name string
	age int
	Class int
}		//单结构体定义

type DigitalProductInfo struct{
	Edition string
	UserName string
	State string
}
type BasicPhoneInfo struct{
	CameraName string
	Soc string
	Battery int
}			//抽离公共部分定义新结构体

type PhoneInfo struct {
	Digital DigitalProductInfo
	Basic BasicPhoneInfo
}
type Mp3Info struct{
	Digital DigitalProductInfo
	AudioChip string
}				//将公共结构体用于原结构体嵌套，更加简洁

func (S2 Student) updateName(){
	S2.Name="张五"
}	//值接收

func(S2 *Student) updateAge(){
	S2.age=111
} //指针接收

//定义接口
type WorkInter interface{
	//work()//函数声明，不用在这儿实现
	IsStudent(v interface{})
}

//空接口
type workinter interface{}

func (s*Student)work(){
	fmt.Println(s.Name,"的班级是",s.Class)
}
//work函数实现
func IsStudent(v interface{})  {
	_,ok := v.(Student)
	if !ok {
		fmt.Println("不是学生")
		return
	}
	fmt.Println("是学生")
}

func main(){
	Person1:=Student{
		"张三",
		18,
		13002106,
	}
	fmt.Println(Person1)
	fmt.Printf("姓名:%s,班级:%d,年龄:%d\n",
	Person1.Name, Person1.age, Person1.Class)		//单结构体的 定义和访问

	a:=PhoneInfo{
		Digital:DigitalProductInfo{
			Edition:  "v100",
			UserName: "xiaoA",
			State:    "new",
		},
		Basic:BasicPhoneInfo{
			CameraName: "pix10000000",
			Soc:        "kirin999",
			Battery:    4000,
		},
	}				//嵌套结构体的定义
	fmt.Println(a)
	fmt.Println("Battery:",a.Basic.Battery)
	//打印,访问
	x,y := 1,1
	var z *int = &x // 取地址符
	fmt.Printf("x=%d,y=%d,z=%d\n", x, y, *z)
	y = 2
	fmt.Printf("x=%d,y=%d,z=%d\n", x, y, *z)
	*z = 3
	fmt.Printf("x=%d,y=%d,z=%d\n", x, y, *z)

	var p1 *string
	fmt.Printf("p1的值是%v\n", p1)//空指针

	/*指针小练习：程序定义一个int变量num的地址并打印
	将num的地址赋给指针ptr，并通过ptr去修改num的值*/
	var num int =1
	ptr:=&num
	fmt.Printf("修改前num的值：%d \n",num)
	*ptr+=1
	fmt.Printf("修改后num的值：%d \n",num)

	//使用值接受者和指针接受者
	 S2:=Student{
		Name:  "校长",
		age:   18,
		Class: 13002106,
	}		//定义原始结构体、
	fmt.Println("S2的原始属性：",S2)
	 S2.updateName()
	fmt.Println("经过值接收函数后S2的属性：",S2)
	 S2.updateAge()
	fmt.Println("经过指针接收函数后S2的属性：",S2)

	/*var xiaozhang WorkInter=&Student{
		"小张",
		18,
		13002106,
	}*/
	//xiaozhang.work()//调用被接口声明的函数

	IsStudent(Person1)
	}
func (p PhoneInfo) Open(a int) error {
	p.Digital.State = "open"
	return nil
}		//结构体方法。func （接收器变量 类型）方法名（入参）（返回参）{函数体}
//方法调用      var p1 PhoneInfo	         p1.Open()