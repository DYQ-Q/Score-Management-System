#include <stdio.h>
// 定义颜色宏
#define COLOR_RED     "\033[0;31m"
#define COLOR_GREEN   "\033[0;32m"
#define COLOR_YELLOW  "\033[0;33m"
#define COLOR_BLUE    "\033[0;34m"
#define COLOR_RESET   "\033[0m"

typedef double calculator(double, double);

double callback(calculator func, double a, double b);
double add(double a, double b);
double sub(double a, double b);
double mul(double a, double b);
double div(double a, double b);


int main()
{
    system("chcp 65001 > nul"); 
    double a, b;
    int choice; 

    while (1)
    {
        printf("1.加法\n");
        printf("2.减法\n");
        printf("3.乘法\n");
        printf("4.除法\n");
        printf("5.退出\n");
        printf("请输入您的选择：");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("谢谢使用！\n");
            break;
        }

        if (choice != 1 && choice != 2 && choice != 3 && choice != 4) {
            printf("无效的选择，请重新输入。\n");
            printf(COLOR_RED "------------------------------\n" COLOR_RESET);
            continue; // 如果输入的不是1、2、3、4、5，则重新开始循环
        }

        printf(COLOR_GREEN "------------------------------\n" COLOR_RESET);
        printf("请输入两个数(空格分隔):");
        scanf("%lf %lf", &a, &b);

        if (choice == 4 && b == 0.0) {
            printf("错误：除数不能为0！\n");
            continue; 
        }

        switch (choice)
        {
        case 1:
            printf("结果为：%.2lf\n", callback(add, a, b));
            break;
        case 2:
            printf("结果为：%.2lf\n", callback(sub, a, b));
            break;
        case 3:
            printf("结果为：%.2lf\n", callback(mul, a, b));
            break;
        case 4:
            printf("结果为：%.2lf\n", callback(div, a, b));
            break;
        default:
            printf("无效的选择，请重新输入。\n");
            break;
        }
        printf(COLOR_RED "------------------------------\n" COLOR_RESET);
    }
    return 0;
}

double callback(calculator func, double a, double b)
{
    return func(a, b);
}

double add(double a, double b)
{
    return a + b;
}

double sub(double a, double b)
{
    return a - b;
}

double mul(double a, double b)
{
    return a * b;
}

double div(double a, double b)
{
    return a / b;
}
