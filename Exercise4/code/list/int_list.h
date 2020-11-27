#include <stdio.h>
#include <stdlib.h>
typedef enum boolean_enum {TRUE=1, FALSE=0} bool;
typedef struct Int_List_entry_struct
{
   int                           value;
   struct Int_List_entry_struct* next;
   struct Int_List_entry_struct* prev;
} Int_List_entry;

typedef struct int_List_struct
{
   Int_List_entry* head;
   Int_List_entry* tail;
   Int_List_entry* iter;
   int             size;
} Int_List;

/* Basic List Operations */
  /* create and destroy */
    /* setting Int_List entries to NULL */
    void init_int_list(Int_List*);
    /* delete all entries and reinit list */
    void free_int_list(Int_List*);

  /* state request */
    /* TRUE if list is empty */
    bool empty_int_list(Int_List*);
    /* returns size of given list */
    int  size_int_list(Int_List*);

  /* append and prepend entries */
    /* appends value to list back */
    void append_int_list(Int_List*,int);
    /* prepends value to list front */
    void prepend_int_list(Int_List*,int);

  /* insert list into list */
    /* inserts second list into the first at position of iter */
    /* second list is empty after this operation*/
    void int_list_insert_at_iter(Int_List*,Int_List*);

/* ITERATOR FUNCTIONS */
  /* move iter to tail or head of list*/
    void tail_int_list_iter(Int_List*);
    void head_int_list_iter(Int_List*);

  /* reading and writing value at position of iter */
    int  read_int_list_iter(Int_List*);
    void write_int_list_iter(Int_List*, int);

  /* increment decrement iterator (move right/left) */
  /* if decrement or increment at head or tail respectively */
  /* the iterator points to NULL */
    void incr_int_list_iter(Int_List*);
    void decr_int_list_iter(Int_List*);

  /* state request of iterator */
    /* return iter==tail */
    bool is_tail_int_list_iter(Int_List*);
    /* return iter==head */
    bool is_head_int_list_iter(Int_List*);
    /* return iter==NULL */
    bool is_NULL_int_list_iter(Int_List*);
