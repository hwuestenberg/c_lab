#include "int_list.h"
#include <assert.h>
#include <stdio.h>
int main()
{
  int i;
  Int_List list1;
  Int_List list2;
  init_int_list(&list1);
  init_int_list(&list2);
  
  for(i=0;i<10;i++)
  {
    append_int_list(&list1,i);
  }
  assert(size_int_list(&list1)==10);
  printf("MARK1\n");
  /* testing for loop with use of iterator*/ 
  for( head_int_list_iter(&list1),i=0;
       !is_NULL_int_list_iter(&list1);
       incr_int_list_iter(&list1),i++)
  {
	printf("%i\n",list1.iter->value);
    assert(read_int_list_iter(&list1)==i);
    printf("List[%i]==%i\n",i,read_int_list_iter(&list1));
  }
  free_int_list(&list1);
  for(i=0;i<10;i++)
  {
    append_int_list(&list1,i);
    append_int_list(&list2,10+i);
  }
  tail_int_list_iter(&list1);
  assert(is_tail_int_list_iter(&list1));
  int_list_insert_at_iter(&list1,&list2);
  assert(size_int_list(&list2)==0);
  assert(size_int_list(&list1)==20);
  printf("MARK2\n");
  
  for(head_int_list_iter(&list1),i=0;
       !is_NULL_int_list_iter(&list1);
       incr_int_list_iter(&list1),i++ ) 
  {
    assert(read_int_list_iter(&list1)==i);
    printf("List[%i]==%i\n",i,read_int_list_iter(&list1));
  }
  printf("%i\n",i);
  assert(i==20);
  free_int_list(&list1);
  free_int_list(&list2);
  printf("TEST SUCCEEDED\n");
  return 0;
}
