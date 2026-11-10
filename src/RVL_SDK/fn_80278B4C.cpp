#pragma force_active on
struct Argument { char pad[0x10]; float value; };
class Object_vptr_0 {
public:
virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual void slot3();
virtual void slot4();
virtual void slot5();
virtual void slot6();
virtual void slot7();
virtual void slot8();
virtual void slot9();
virtual void slot10();
virtual void slot11();
virtual void slot12();
virtual void slot13();
virtual void slot14();
virtual void slot15();
virtual void slot16();
virtual void slot17();
virtual void slot18();
virtual void slot19();
virtual void slot20(Argument*, int, int);
char pad0[8];
float value;
char pad1[4];
int state;
char pad2[8];
struct List* list;
Argument* argument;
};
struct Node { Node* next; char pad[4]; Object_vptr_0* object; };
struct List { char pad[0x10]; Node sentinel; };
extern "C" void fn_80278B4C(Object_vptr_0* self) {
Node* node;
Node* sentinel;
int flag;
if (self->state == 1) {
self->slot1();
flag = 1;
self->argument->value = self->value;
} else flag = 0;
sentinel = &self->list->sentinel;
node = sentinel->next;
while(node != sentinel) {
node->object->slot20(self->argument, flag, 0);
node = node->next;
}
}