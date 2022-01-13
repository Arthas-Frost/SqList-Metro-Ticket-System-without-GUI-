// Metro.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdio.h>
#include "Sqlist.h"
#include <stdlib.h>
#include <ctime>
using namespace std;
SqList L;
station* num1;
int show_identity(bool a)//身份输出函数
{   

    switch (a)
    {
        case 0:
            cout << "您的身份为:乘客\n"<<endl;
            break;
        case 1:
            cout << "您的身份为:管理员\n" << endl;
            break;
    }
    return 0;
}
void window(const char name[10])//窗口管理函数
{
    if (name == "head") {//封装
        cout << "-------------------------------------------------------------------\n欢迎使用OGAS地铁订票系统\n请选择您要执行的操作:\n" << endl;
    }
    if (name == "boot") {//封装
        cout << show_identity(identity)+"-------------------------------------------------------------------\n" << endl;
    }
    if (name == "main") {
        switch (identity) {

        case 0:
            window("head");
            cout << "\t清屏：/clear\n" << endl;
            cout << "\t切换身份：/id\n" << endl;
            cout << "\t查询车站信息：/search\n" << endl;
            cout << "\t查询票价：/buy\n" << endl;
            cout << "\t票价列表：/cost\n" << endl;
            cout << "\t列出所有站：/list\n" << endl;
            window("boot");
            break;

        case 1:
            window("head");
            cout << "\t清屏：/clear\n" << endl;
            cout << "\t切换身份：/id\n" << endl;
            cout << "\t查询车站信息：/search\n" << endl;
            cout << "\t查询票价：/buy\n" << endl;
            cout << "\t票价列表：/cost\n" << endl;
            cout << "\t列出所有站：/list\n" << endl;
            cout << "\t编辑车站：/edit\n" << endl;
            cout << "\t新增车站：/adds\n" << endl;
            cout << "\t删除车站：/remove\n" << endl;
            cout << "\t按客流量排序：/sort\n" << endl;
            window("boot");
            break;

        }
    }
}

void id_change()
{
    string password ="";
    cout << "请输入密码：\n" << endl;
    cin >> password;
    if (password == "OGAS") {
        identity = !identity;
        window("main");
    }
    else {
        cout << "密码错误，返回主页面\n" << endl;
        window("main");
    }
       
}



void sortselect() {
    int choice = 0;
    cout << "请选择您要使用的排序方式" << endl;
    cout << "1 折半插入排序\n" <<"2 冒泡排序\n"<<"3 希尔排序（不稳定）\n" <<"4 二路归并排序\n" << "5 快速排序（不稳定）\n" << endl;
    cin >> choice;
    switch (choice) {
        case 1:
            BISort(L, L.length);
            break;
        case 2:
            bubble(L);
        case 3:
            ShellSort(L, L.length);
            break;
        case 4:
            Mergesort(L, L.length);
            break;
        case 5:
            FSprint(L);
        default: 
        cout << "请输入有效的排序序号" << endl;
        break;
    }
}
void command() //命令控制函数
{
        string command;
        cout<<"#"; cin >> command;
        if (command == "/id")id_change();
        else if (command == "/clear")window("main");
        else if (command == "/buy")Price(&L);
        else if (command == "/list")Printall(&L);
        else if (command == "/cost")Cost(&L);
        else if (command == "/search")search(&L);
        else if (command == "/edit" && identity == 1)edit(&L);
        else if (command == "/adds" && identity == 1)adds(&L);
        else if (command == "/remove" && identity == 1)remove(&L);
        else if (command == "/sort" && identity == 1)sortselect();
        else cout << "请输入正确的指令\n" << endl;
}

int main()
{
    srand(time(NULL));
    CreateList(&L,num1);
    window("main");
    while (1) { command(); };
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
