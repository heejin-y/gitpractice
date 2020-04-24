/*
 * circularQ.c
 *
 */
//2019038072 양희진

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 4

typedef char element;
typedef struct {
	element queue[MAX_QUEUE_SIZE];//큐 배열
	int front, rear;
}QueueType; //큐타입이란 구조체 데이터형 정의


QueueType *createQueue(); 
int isEmpty(QueueType *cQ);
int isFull(QueueType *cQ);
void enQueue(QueueType *cQ, element item);
int deQueue(QueueType *cQ, element* item);
void printQ(QueueType *cQ);
void debugQ(QueueType *cQ);

element getElement();
//함수 원형정의

int main(void)
{
	QueueType *cQ = createQueue();//구조체변수를가리키는포인터에 큐를 만들어서 주소를 대입
	element data; //char형 변수

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
			data = getElement(); //한문자 집어넣음
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


QueueType *createQueue()//구조체 포인터형 반환
{
	QueueType *cQ;
	cQ = (QueueType *)malloc(sizeof(QueueType));//큐타입크기만큼 동적할당후 시작주소 반환
	cQ->front = 0;//cQ 포인터 변수가 가리키는 구조체변수의 멤버 front에 0대입
	cQ->rear = 0;
	return cQ;//포인터 반환
}

element getElement()
{
	element item;//char형 변수 정의
	printf("Input element = ");
	scanf(" %c", &item);
	return item; //값 반환하고 item변수는 메모리에서 사라짐
}


/* complete the function */
int isEmpty(QueueType *cQ)
{
		if (cQ->front == cQ->rear)//front와 rear가 같으면 큐는 비어있는 상태 
			return 1;
		else 
			return 0;
}

/* complete the function */
int isFull(QueueType *cQ)
{
	int tmp = (cQ->rear + 1) % MAX_QUEUE_SIZE; //원형 큐에서 rear+1을 MAX로 나눈 나머지값이
	if (tmp == cQ->front)//front와 같으면 큐는 가득차 있는 상태 
		return 1;
	else
		return 0;
}


/* complete the function */
void enQueue(QueueType *cQ, element item)//ecQueue(cQ,data);이렇게 이용
{
	//cQ는 큐의 시작주소 들어가있음, 함수 실행될때 큐 만들어져 있음
	/*(cQ->rear) = ((cQ->rear) + 1) % MAX_QUEUE_SIZE;*/
	if (isFull==1)
		printf("큐가 가득 차있으므로 큐에 넣을수 없습니다.");
	else
		(cQ->queue)[(cQ->rear)] = item;

}

/* complete the function */
int deQueue(QueueType *cQ, element *item)
{
	if (isEmpty == 1)
		printf("큐가 비어있으므로 삭제할수 없습니다.");
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

