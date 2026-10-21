#include <types.h>
#pragma force_active on
extern "C" { extern const f32 lbl_805A3510; }
struct Node {
    Node* prev;
    Node* next;
};
struct Work {
    u32 count;
    void* prev;
    void* next;
    u16 flag;
    f32 value;
};
extern "C" void fn_801BF440(Work* self) {
    self->prev = 0;
    self->next = 0;
    self->count = 0;
    Node* head = (Node*)&self->prev;
    head->prev = head;
    head->next = head;
    self->flag = 1;
    self->value = lbl_805A3510;
}