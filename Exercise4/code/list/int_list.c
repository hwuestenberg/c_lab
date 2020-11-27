#include "int_list.h"

/* Basic List Operations */
  /* create and destroy */
    /* setting Int_List entries to NULL */
void init_int_list(Int_List* pList) {
	pList->head = NULL;	
	pList->tail = NULL;	
	pList->iter = NULL;
	pList->size = 0;
}
    /* delete all entries and reinit list */
void free_int_list(Int_List* pList) {
	if(!empty_int_list(pList)) {
		tail_int_list_iter(pList);
		
		// Delete all entries beginning at the tail	
		while(!is_head_int_list_iter(pList)) {
			decr_int_list_iter(pList);
			pList->iter->next = NULL;
			pList->size--;
		}
	}
	init_int_list(pList);	// Head+Tail+Iter/size = NULL/0
}

  /* state request */
    /* TRUE if list is empty */
bool empty_int_list(Int_List* pList) {
	return pList->size==0;
}
    /* returns size of given list */
int  size_int_list(Int_List* pList) {
	return pList->size;
}

  /* append and prepend entries */
    /* appends value to list */
void append_int_list(Int_List* pList,int value) {
	// Initialize new entry
	Int_List_entry* new_entry = (Int_List_entry*)malloc(sizeof(Int_List_entry*));
	new_entry->value = value;
	new_entry->next = pList->head;
	new_entry->prev = pList->tail;
	
	tail_int_list_iter(pList);	// Move to tail	 	
	if(is_NULL_int_list_iter(pList) && empty_int_list(pList)) {
		pList->tail = new_entry;
		pList->tail->prev = new_entry;
		pList->head = new_entry;
		pList->head->next = new_entry;
	}
	else {
		pList->tail->next = new_entry;
		pList->tail = new_entry;
		pList->head->prev = new_entry;
	}
	pList->iter = new_entry;
	pList->size++;
}
    /* prepends value to list */
void prepend_int_list(Int_List* pList,int value) {
	Int_List_entry* new_entry = (Int_List_entry*)malloc(sizeof(Int_List_entry*));
	
	new_entry->value = value;
	new_entry->next = pList->head;
	new_entry->prev = pList->tail;
	
	head_int_list_iter(pList);	// Move to head
	if(is_NULL_int_list_iter(pList)) {
		pList->head = new_entry;
		pList->head->next = new_entry;
	}
	else {
		pList->head->prev = new_entry;
		pList->head = new_entry;
		pList->tail->next = new_entry;
	}
	if(empty_int_list(pList)) {
		pList->tail = new_entry;
	}
	pList->iter = new_entry;
	pList->size++;
}

  /* insert list into list */
    /* inserts second list into the first at position of iter */
    /* second list is empty after this operation*/
void int_list_insert_at_iter(Int_List* pList1,Int_List* pList2) {
	head_int_list_iter(pList2);		// Set iter to head
	if(is_tail_int_list_iter(pList1) || is_NULL_int_list_iter(pList1)) {
		while(!is_NULL_int_list_iter(pList2)) {
			append_int_list(pList1,pList2->iter->value);
			incr_int_list_iter(pList2);
			pList2->size--;
		}
		free_int_list(pList2);
	}
	else {
		while(!is_NULL_int_list_iter(pList2)) {
			pList1->iter->next->prev = pList2->iter;
			pList2->iter->prev = pList1->iter;
			pList2->iter->next = pList1->iter->next;
			pList1->iter->next = pList2->iter;
			
			incr_int_list_iter(pList2);
			incr_int_list_iter(pList1);
			pList1->size++;
			pList2->size--;
		}
		free_int_list(pList2);
	}
}

/* ITERATOR FUNCTIONS */
  /* move iter to tail or head of List */
void tail_int_list_iter(Int_List* pList) {
	if(is_NULL_int_list_iter(pList)&&!empty_int_list(pList))
		pList->iter = pList->tail;
	while(!is_tail_int_list_iter(pList)) // Increment until tail
		incr_int_list_iter(pList);

}

void head_int_list_iter(Int_List* pList){
	if(is_NULL_int_list_iter(pList)&&!empty_int_list(pList))
		pList->iter = pList->head;
	while(!is_head_int_list_iter(pList)) // Decrement until head
		decr_int_list_iter(pList);
}

  /* reading and writing value at position of iter */
int  read_int_list_iter(Int_List* pList) {
	return pList->iter->value;
}

void write_int_list_iter(Int_List* pList, int value) {
	pList->iter->value = value;
}

  /* increment decrement iterator (move right/left) */
  /* if decrement or increment at head or tail respectively */
  /* the iterator points to NULL */
void incr_int_list_iter(Int_List* pList) {
	if(is_tail_int_list_iter(pList))
		pList->iter = NULL;
	else
		pList->iter = pList->iter->next;
}

void decr_int_list_iter(Int_List* pList) {
	if(is_head_int_list_iter(pList))
		pList->iter = NULL;
	else
		pList->iter = pList->iter->prev;
}

  /* state request of iterator */
    /* return iter==tail */
bool is_tail_int_list_iter(Int_List* pList) {
	return (pList->iter == pList->tail);
}
    /* return iter==head */
bool is_head_int_list_iter(Int_List* pList) {
	return (pList->iter == pList->head);
}
	/* return iter==NULL */
bool is_NULL_int_list_iter(Int_List* pList) {
	return (pList->iter == NULL);
}
