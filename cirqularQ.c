/*
 * circularQ.c
 *
 */
//2019038072 ������

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 4

typedef char element;
typedef struct {
	element queue[MAX_QUEUE_SIZE];//ť �迭
	int front, rear;
}QueueType; //ťŸ���̶� ����ü �������� ����


QueueType *createQueue(); 
int isEmpty(QueueType *cQ);
int isFull(QueueType *cQ);
void enQueue(QueueType *cQ, element item);
int deQueue(QueueType *cQ, element* item);
void printQ(QueueType *cQ);
void debugQ(QueueType *cQ);

element getElement();
//�Լ� ��������

int main(void)
{
	QueueType *cQ = createQueue();//����ü����������Ű�������Ϳ� ť�� ���� �ּҸ� ����
	element data; //char�� ����

	char command;

	do {
		printf("\n-----------------------------------------------------\n");
		printf("                     Circular Q                   \n");
		printf("------------------------------------------------------\n");
		printf(" Insert=i,  Delete=d,   PrintQ=p,   Dubug=b,   Quit=q \n");
		printf("------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch (command) {
		case 'i': case 'I':
			data = getElement(); //�ѹ��� �������
			enQueue(cQ, data);
			break;
		case 'd': case 'D':
			deQueue(cQ, &data);
			break;
		case 'p': case 'P':
			printQ(cQ);
			break;
		case 'b': case 'B':
			debugQ(cQ);
			break;
		case 'q': case 'Q':
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	} while (command != 'q' && command != 'Q');


	return 1;
}


QueueType *createQueue()//����ü �������� ��ȯ
{
	QueueType *cQ;
	cQ = (QueueType *)malloc(sizeof(QueueType));//ťŸ��ũ�⸸ŭ �����Ҵ��� �����ּ� ��ȯ
	cQ->front = 0;//cQ ������ ������ ����Ű�� ����ü������ ��� front�� 0����
	cQ->rear = 0;
	return cQ;//������ ��ȯ
}

element getElement()
{
	element item;//char�� ���� ����
	printf("Input element = ");
	scanf(" %c", &item);
	return item; //�� ��ȯ�ϰ� item������ �޸𸮿��� �����
}


/* complete the function */
int isEmpty(QueueType *cQ)
{
		if (cQ->front == cQ->rear)//front�� rear�� ������ ť�� ����ִ� ���� 
			return 1;
		else 
			return 0;
}

/* complete the function */
int isFull(QueueType *cQ)
{
	int tmp = (cQ->rear + 1) % MAX_QUEUE_SIZE; //���� ť���� rear+1�� MAX�� ���� ����������
	if (tmp == cQ->front)//front�� ������ ť�� ������ �ִ� ���� 
		return 1;
	else
		return 0;
}


/* complete the function */
void enQueue(QueueType *cQ, element item)//ecQueue(cQ,data);�̷��� �̿�
{
	//cQ�� ť�� �����ּ� ������, �Լ� ����ɶ� ť ������� ����
	/*(cQ->rear) = ((cQ->rear) + 1) % MAX_QUEUE_SIZE;*/
	if (isFull==1)
		printf("ť�� ���� �������Ƿ� ť�� ������ �����ϴ�.");
	else
		(cQ->queue)[(cQ->rear)] = item;

}

/* complete the function */
int deQueue(QueueType *cQ, element *item)
{
	if (isEmpty == 1)
		printf("ť�� ��������Ƿ� �����Ҽ� �����ϴ�.");
	/*(cQ->front) = ((cQ->front) + 1) % MAX_QUEUE_SIZE;*/
	else
		(cQ->front) = (cQ->front + 1) % MAX_QUEUE_SIZE;
		
	return (cQ->queue)[(cQ->front)];
}


void printQ(QueueType *cQ)
{
	int i, first, last;

	first = (cQ->front + 1) % MAX_QUEUE_SIZE;
	last = (cQ->rear + 1) % MAX_QUEUE_SIZE;

	printf("Circular Queue : [");

	i = first;
	while (i != last) {
		printf("%3c", cQ->queue[i]);
		i = (i + 1) % MAX_QUEUE_SIZE;

	}
	printf(" ]\n");
}


void debugQ(QueueType *cQ)
{

	printf("\n---DEBUG\n");
	for (int i = 0; i < MAX_QUEUE_SIZE; i++)
	{
		if (i == cQ->front) {
			printf("  [%d] = front\n", i);
			continue;
		}
		printf("  [%d] = %c\n", i, cQ->queue[i]);

	}
	printf("front = %d, rear = %d\n", cQ->front, cQ->rear);
}

