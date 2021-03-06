#ifndef queue_Header_h
#define queue_Header_h
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//队列的结点结构
typedef struct Node{
    int data;
    struct Node *next;
} Node, *Queue;

//队列的结构，嵌套
typedef struct{
    Queue front;
    Queue rear;
} LinkQueue;

//初始化
//开始必然是空队列，队尾指针和队头指针都指向头结点
void initQueue(LinkQueue *queue)
{
    //初始化头结点
    queue->front = queue->rear = (Queue)malloc(sizeof(Node));
    
    if (NULL == queue->front) {
        exit(0);
    }
    
    queue->front->next = NULL;
}

//判空
bool isEmpty(LinkQueue queue)
{
    return queue.rear == queue.front ? true : false;
}

//入队,只在一端入队，另一端出队，同样入队不需要判满
void insertQueue(LinkQueue *queue, int temp)
{
    Queue q = (Queue)malloc(sizeof(Node));
    
    if (NULL == q) {
        exit(0);
    }
    //插入数据
    q->data = temp;
    q->next = NULL;
    //rear 总是指向队尾元素
    queue->rear->next = q;
    queue->rear = q;
}

//出队，需要判空
void deleteQueue(LinkQueue *queue)
{
    Queue q = NULL;
    
    if (!isEmpty(*queue)) {
        q = queue->front->next;
        queue->front->next = q->next;
        //这句很关键，不能丢
        if (queue->rear == q) {
            queue->rear = queue->front;
        }
        
        free(q);
    }
}

//遍历
void traversal(LinkQueue queue)
{
    int i = 1;
    Queue q = queue.front->next;
    
    while (q != NULL) {
        printf("队列第%d个元素是：%d\n", i, q->data);
        q = q->next;
        i++;
    }
}

//销毁
void destoryQueue(LinkQueue *queue)
{
    while (queue->front != NULL) {
        queue->rear = queue->front->next;
        free(queue->front);
        queue->front = queue->rear;
    }
    
    puts("销毁成功！");
}

#endif

int main(int argc, const char * argv[])
{
    LinkQueue queue;
    puts("初始化队列 queue");
    initQueue(&queue);
    traversal(queue);
    
    puts("队尾依次插入0 1 2 3");
    insertQueue(&queue, 0);
    insertQueue(&queue, 1);
    insertQueue(&queue, 2);
    insertQueue(&queue, 3);
    traversal(queue);
    
    puts("先进先出，删除队列从头开始， 0 ");
    deleteQueue(&queue);
    traversal(queue);
    
    puts("先进先出，删除队列从头开始， 1 ");
    deleteQueue(&queue);
    traversal(queue);
    
    puts("先进先出，删除队列从头开始， 2 ");
    deleteQueue(&queue);
    traversal(queue);
    
    puts("先进先出，删除队列从头开始， 3");
    deleteQueue(&queue);
    traversal(queue);
    
    destoryQueue(&queue);
    return 0;
}
