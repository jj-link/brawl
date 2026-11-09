#pragma force_active on
struct Node { Node* next; unsigned char pad[12]; unsigned int id; unsigned char pad2[8]; unsigned char flags; unsigned char value; };
struct List { unsigned char pad[0x68]; unsigned int length; Node* head; };
inline Node* find(List* list, unsigned int a, unsigned int b) {
 if (list->length) {
  for (Node* result = list->head; result != (Node*)&list->head; result = result->next) {
   if (((result->flags >> 7) & 1) && a == result->value && b == result->id) return result;
  }
 }
 return 0;
}
extern "C" Node* fn_80012324(List* list, unsigned int a, unsigned int b) {
 return find(list, a, b);
}
