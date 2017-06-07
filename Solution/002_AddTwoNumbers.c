/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	int tmp = 0;

	struct ListNode* retls = NULL;
	retls = malloc(sizeof(struct ListNode));
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
			curret->next = malloc(sizeof(struct ListNode));
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
			curret->next = malloc(sizeof(struct ListNode));
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
			curret->next = malloc(sizeof(struct ListNode));
			curret->next->val = tmp / 10;
			curret->next->next = NULL;
			curret = curret->next;
		}

		curl2 = curl2->next;
	}

	return retls;
}
