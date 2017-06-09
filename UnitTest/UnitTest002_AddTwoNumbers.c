#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	int tmp = 0;

	struct ListNode* retls = NULL;
	retls = (struct ListNode*)malloc(sizeof(struct ListNode));
	if(retls == NULL) {
		printf("malloc failed!\n");
		return retls;
	}
	retls->val = 0;
	retls->next = NULL;

	struct ListNode *curl1 = l1;
	struct ListNode *curl2 = l2;
	struct ListNode *curret = retls;

	while((curl1 != NULL) && (curl2 != NULL)) {
		tmp = curret->val + curl1->val + curl2->val;
		curret->val = tmp % 10;

		if((curl1->next == NULL) && (curl2->next == NULL) && (tmp < 10)) {
			curret->next = NULL;
		}
		else {
			// Adding an new item to the end of the retls.
			curret->next = (struct ListNode*)malloc(sizeof(struct ListNode));
			curret->next->val = tmp / 10;
			curret->next->next = NULL;
			curret = curret->next;
		}

		curl1 = curl1->next;
		curl2 = curl2->next;
	}

	while(curl1 != NULL) {
		tmp = curret->val + curl1->val;
		curret->val = tmp % 10;

		if((curl1->next == NULL) && (tmp < 10)) {
			curret->next = NULL;
		}
		else {
			curret->next = (struct ListNode*)malloc(sizeof(struct ListNode));
			curret->next->val = tmp / 10;
			curret->next->next = NULL;
			curret = curret->next;
		}

		curl1 = curl1->next;
	}

	while(curl2 != NULL) {
		tmp = curret->val + curl2->val;
		curret->val = tmp % 10;

		if((curl2->next == NULL) && (tmp < 10)) {
			curret->next = NULL;
		}
		else {
			curret->next = (struct ListNode*)malloc(sizeof(struct ListNode));
			curret->next->val = tmp / 10;
			curret->next->next = NULL;
			curret = curret->next;
		}

		curl2 = curl2->next;
	}

	return retls;
}

int main() {
	struct ListNode *l1 = NULL;
	l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	if(l1 == NULL) {
		printf("malloc l1 failed!\n");
		return 0;
	}
	l1->val = 2;
	l1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
	l1->next->val = 4;
	l1->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
	l1->next->next->val = 3;
	l1->next->next->next = NULL;

	struct ListNode *current = l1;
	printf("Input: (");
	while(current != NULL) {
		if(current->next == NULL) {
			printf("%d) + (", current->val);
		}
		else {
			printf("%d->", current->val);
		}
		current = current->next;
	}

	struct ListNode *l2 = NULL;
	l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	if(l2 == NULL) {
		printf("malloc l2 failed!\n");
		return 0;
	}
	l2->val = 5;
	l2->next = (struct ListNode*)malloc(sizeof(struct ListNode));
	l2->next->val = 6;
	l2->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
	l2->next->next->val = 4;
	l2->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
	l2->next->next->next->val = 7;
	l2->next->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
	l2->next->next->next->next->val = 1;
	l2->next->next->next->next->next = NULL;

	current = l2;
	while(current != NULL) {
		if(current->next == NULL) {
			printf("%d)\n", current->val);
		}
		else {
			printf("%d->", current->val);
		}
		current = current->next;
	}

	struct ListNode *reslist = addTwoNumbers(l1, l2);

	current = reslist;
	printf("Output: ");
	while(current != NULL) {
		if(current->next == NULL) {
			printf("%d\n", current->val);
		}
		else {
			printf("%d->", current->val);
		}
		current = current->next;
	}
}
