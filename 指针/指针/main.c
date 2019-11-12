#include <stdio.h>
#include <stdlib.h>
/* 定义堆栈的最大元素个数 */
#define MAX_ITEMS 20

/* 定义一个boolean型枚举类型 */
typedef enum{FALSE, TRUE} boolean;

/* 定义一个表示堆栈的结构体 */
typedef struct
{
    int items[MAX_ITEMS];
    int top;
} Stack;

/* 创建一个堆栈
 *        返回值 : 返回创建的堆栈结构体地址
 */
Stack *stack_create(void)
{
    Stack *s = malloc(sizeof(Stack));    // 分配一个堆栈空间
    if(NULL == s)    // 分配失败
    {
        return NULL;
    }
    else    // 分配成功
    {
        s->top = 0;
        return s;
    }
}

/*    销毁一个堆栈
 *        s : 要销毁的堆栈的指针的指针
 */
void stack_destroy(Stack **s)
{
    if(NULL != *s)
    {
        free(*s);    // 执行销毁操作
    }
}

/*    判断堆栈是否为空函数
 *        s : 表示要判断的堆栈
 *        返回值: TRUE为空，FALSE为非空
 */
boolean stack_empty(Stack *s)
{
    if(s->top == 0) return TRUE;
    else return FALSE;
}

/*    判断堆栈是否为满函数
 *        s : 表示要判断的堆栈
 *        返回值: TRUE表示满，FALSE表示非满
 */
boolean stack_full(Stack *s)
{
    if(s->top == MAX_ITEMS) return TRUE;
    else return FALSE;
}

/*    向栈顶插入一个元素
 *        s : 要插入的堆栈
 *        item : 要掺入的元素
 *        返回值: TRUE成功，FALSE失败
 */
boolean stack_push(Stack *s, int item)
{
    if(stack_full(s)) return FALSE;
    else    // 如果堆栈未满
    {
        // 先将元素压入堆栈，然后堆栈指针加一
        s->items[s->top] = item;
        s->top++;
        return TRUE;
    }
}

/*    将栈顶元素弹出
 *        s : 要操作的堆栈
 *        返回值: 返回弹出的值，为0表示弹出失败
 */
int stack_pop(Stack *s)
{
    if(stack_empty(s)) return 0;
    else    // 如果堆栈不为空
    {
        s->top--;
        return s->items[s->top];
    }
}

/*    获取栈顶元素
 *        s : 要操作的堆栈
 *        返回值 : 返回堆栈元素值，为0表示获取失败
 */
int stack_get_top(Stack *s)
{
    if(stack_empty(s)) return 0;
    else    // 如果不为空，返回堆栈的值
    {
        return s->items[s->top - 1];
    }
}

/*    打印堆栈元素的函数
 *        s : 要打印的堆栈
 */
void stack_print(Stack *s)
{
    int top = s->top;
    
    printf("Stack : ");
    while(top)
    {
        printf("%d ", s->items[--top]);
    }
    printf("\n");
}

/* 程序的入口函数 */
int main()
{
    int a[10];
    int i;
    
    /* 向数组中输入10个数字 */
    printf("Input 10 numbers : \n");
    for(i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }
    
    printf("*********************************************************\n");
    
    Stack *stack = stack_create();    // 创建一个堆栈
    if(NULL == stack)
    {
        printf("stack_create error!\n");
        return -1;
    }
    
    /* 将10个元素压入堆栈 */
    for(i = 0; i < 10; i++)
    {
        if(stack_push(stack, a[i]) == FALSE)
        {
            printf("stack_push error!\n");
            return -1;
        }
    }
    
    /* 将压入堆栈的元素显示出来 */
    stack_print(stack);
    
    /* 向栈顶插入一个元素 */
    stack_push(stack, 128);
    /* 将压入堆栈的元素显示出来 */
    stack_print(stack);
    
    /* 从栈顶弹出两个元素 */
    stack_pop(stack);
    stack_pop(stack);
    /* 将压入堆栈的元素显示出来 */
    stack_print(stack);
    
    printf("*********************************************************\n");
    
    /* 打印栈顶元素 */
    printf("the top value is %d.\n", stack_get_top(stack));
    
    stack_destroy(&stack);    // 销毁一个堆栈
    
    return 0;
}

