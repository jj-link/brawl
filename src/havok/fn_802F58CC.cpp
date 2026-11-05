#include <types.h>
#pragma force_active on
struct Node { u32 pad0; s16 value; u16 pad6; Node* next; Node* other; s16 otherValue; };
struct Object { char pad0[0x10]; Node* head; char pad14[0x14]; Node* tail; };
extern "C" void fn_802F58CC(Object* obj, Node* oldNode, Node* newNode, s16 value) {
    Node* tail;
    Node* node;
    node = obj->head;
    tail = obj->tail;
    if (node == 0) {
        if (tail != 0) { tail->other = newNode; tail->otherValue = value; }
    } else if (node == oldNode) {
        obj->head = newNode;
        if (tail != 0) { tail->other = newNode; tail->otherValue = value; }
    } else {
    loop:
        Node* next = node->next;
        if (next != oldNode) {
            node = next;
            goto loop;
        }
        node->next = newNode;
        node->value = value;
    }
}