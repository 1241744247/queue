#include"Queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->_front = NULL;
	pq->_rear = NULL;

}
void QueueDestory(Queue* pq)
{
	assert(pq);
	QueueNode* cur;
	cur = pq->_front;
	while (cur)
	{
		pq->_front = cur->_next;
		free(cur);
		cur = pq->_front;
	}
	pq->_front = NULL;
	pq->_rear = NULL;
}

QueueNode* BuyQueueNode(QUDataType x)
{
	QueueNode* cur;
	cur = (QueueNode*)malloc(sizeof(QueueNode));
	cur->_data = x;
	cur->_next = NULL;
	return cur;
}
void QueuePush(Queue* pq, QUDataType x)
{
	assert(pq);
	QueueNode* cur = BuyQueueNode(x);
	if (pq->_front == NULL)
	{
		pq->_front = cur;
		pq->_rear = cur;
	}
	else
	{
		pq->_rear->_next = cur;
		pq->_rear = cur;
	}
}
void QueuePop(Queue* pq)
{
	assert(pq);
	QueueNode* cur;
	cur = pq->_front;
	pq->_front = pq->_front->_next;
	free(cur);
}
QUDataType QueueFront(Queue* pq)
{
	assert(pq);
	return pq->_front->_data;
}
QUDataType QueueBack(Queue* pq)
{
	assert(pq);
	return pq->_rear->_data;
}
int QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->_front == NULL ? 1 : 0;
}
int QueueSize(Queue* pq)
{
	assert(pq);
	int count = 0;
	QueueNode* cur = pq->_front;
	while (cur)
	{
		count++;
		cur = cur->_next;
	}
	return count;
}
void PrintQueue(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->_front;
	while (cur)
	{
		printf("%d ", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}

void TestQueue()
{
	Queue pq;
	QueueInit(&pq);
	QueuePush(&pq, 1);
	QueuePush(&pq, 2);
	QueuePush(&pq, 3);
	QueuePush(&pq, 4);
	QueuePush(&pq, 5);
	QueuePush(&pq, 6);
	QueuePush(&pq, 7);
	QueuePush(&pq, 8);
	QueuePush(&pq, 9);
	QueuePush(&pq, 10);
	QueuePop(&pq);
	QueuePop(&pq);
	QueuePop(&pq);


	printf("%d\n", QueueSize(&pq));
	PrintQueue(&pq);
	QueueDestory(&pq);

}