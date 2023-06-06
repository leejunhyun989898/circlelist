#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

ListNode* insert_first(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
	}
	return head;
}

ListNode* insert_last(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
		head = node;
	}
	return head;
}

ListNode* delete_first(ListNode* head)
{
	if (head == NULL) return NULL;
	ListNode* deleted = head->link;
	if (deleted == head) {
		return NULL;
	}
	head->link = deleted->link;
	free(deleted);
	return head;
}

ListNode* delete_last(ListNode* head)
{
	if (head == NULL) return NULL;

	ListNode* prev = NULL;
	ListNode* curr = head;

	// �� ����Ʈ�� ���
	if (curr->link == head) {
		free(head);
		return NULL;
	}

	// curr�� ������ ��带 ����ų ������ �̵�
	while (curr->link != head) {
		prev = curr;
		curr = curr->link;
	}

	// prev�� ������ ��带 ����Ű�� ����
	prev->link = head; // prev�� link�� head�� ����

	free(curr);
	return head;
}



void print_list(ListNode* head)
{
	ListNode* p;
	if (head == NULL) return;
	p = head->link;
	do {
		printf("%d->", p->data);
		p = p->link;
	} while (p != head->link);
	printf("\n");
}

int main(void)
{
	ListNode* head = NULL;
	int element;
	int s = 0;
	while (1)
	{
		printf("\n= = = = Menu = = = =\n");
		printf("1. Insert First \n2. Insert Last \n3. Delete First \n4. Delete Last\n5. Print List\n0. Exit");
		printf("\nSelect Menu = ");
		scanf_s("%d", &s);
		if (s == 1)
		{
			printf("\nInput first add of list: ");
			scanf_s("%d", &element);
			head = insert_first(head, element);

		}
		else if (s == 2)
		{
			printf("\nInput last add of list: ");
			scanf_s("%d", &element);
			head = insert_last(head, element);

		}
		else if (s == 3)
		{
			head = delete_first(head);
		}
		else if (s == 4)
		{
			head = delete_last(head);
		}
		else if (s == 5)
		{
			print_list(head);
		}
		else if (s == 0)
		{
			printf("Exit the program");
			break;
		}
		else
		{
			printf("�߸��� �Է��Դϴ�. �ٽ� �Է� ���ּ���\n");
		}
	}
	return 0;
}
