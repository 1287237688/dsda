
#include <stdio.h>

#define T 1
#define F 0
#define MAX 10

typedef struct
{
    int a[MAX];
    int *in;
    int *out;
    int count;
}queue;

int init(queue *q);
int inQueue(queue *q, int e);
int outQueue(queue *q, int *e);

int main()
{
    int i, e;
    queue q;
    init(&q);
    for (i = 0; i < 5; i++)
    {
        inQueue(&q, i);
    }
    while (q.count != 0)
    {
        outQueue(&q, &e);
        printf("%d\n", e);
    }
    return 0;
}

int init(queue *q)
{
    q->in = q->a;
    q->out = q->a;
    q->count = 0;
    return T;
}

int inQueue(queue *q, int e)
{
    if (MAX == q->count)
    {
        return F;
    }
    *(q->in) = e;
    q->in ++;
    if (q->in == &(q->a[MAX]))
    {
        q->in = q->a;
    }
    q->count ++;
    return T;
}

int outQueue(queue *q, int *e)
{
    if (0 == q->count)
    {
        return F;
    }
    *e = *(q->out);
    q->out ++;
    if (q->out == &(q->a[MAX]))
    {
        q->out = q->a;
    }
    q->count --;
    return T;
}
