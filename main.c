#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include < windows.h>

#define max_students 100
#define file_name "students.dat"

void add_student();
void show_students();
void save_to_file();
void load_from_file();

typedef struct {
    int id;
    char name[50];
    float score;
}student;

student students[max_students];
int count=0;

int main() 
{
    system("chcp 65001 > nul");  // 切换到 UTF-8，>nul 是隐藏提示信息
    load_from_file();
    int choice;
    while(1)
    {
        //显示菜单
        printf("------------------------------------\n");
        printf("1.添加学生/add student\n");
        printf("2.显示学生/show students\n");
        printf("3.保存到文件save to file\n");
        printf("4.从文件加载/load from file\n");
        printf("5.退出/exit\n");
        printf("请选择操作/please choose an operation:");
        
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                add_student();
                break;
            case 2:
                show_students();
                break;
            case 3:
                save_to_file();
                break;
            case 4:
                load_from_file();
                break;
            case 5:
                exit(0);
        }
    }
    return 0;
}

void add_student()
{
    if(count>=max_students)
    {
        printf("系统已满，无法添加！\n");
        return;
    }
    printf("请输入学号:");
    scanf("%d",&students[count].id);
    printf("请输入姓名:");
    scanf("%S",&students[count].name);
    printf("请输入成绩:");
    scanf("%f",&students[count].score); 
    count++;
    printf("添加成功！\n");
}

void show_students()
{
    printf("------------------------\n");
    printf("学号\t|姓名\t|成绩\n");
    for(int i=0;i<count;i++)
    {
        printf("%d\t|%s\t|%.2f\n",students[i].id,students[i].name,students[i].score);
    }
    printf("------------------------\n");
}

void save_to_file()
{
    FILE *fp=fopen(file_name,"wb");//二进制写模式
    if(fp==NULL)
    {
        printf("文件打开失败！\n");
        return;
    }
    fwrite(students,sizeof(student),count,fp);
    fclose(fp);
    printf("保存成功！\n");
}

void load_from_file()
{
    FILE *fp=fopen(file_name,"rb");
    if(fp==NULL)
    {
        printf("文件打开失败！\n");
        return;
    }
    fread(students,sizeof(student),count,fp);
    fclose(fp);
    printf("加载成功！\n");
}