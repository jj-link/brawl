#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Node {
    struct Node* prev;
    struct Node* next;
    u8 a;
    u8 b;
    u8 data[];
} Node;

typedef struct List {
    Node* head;
    Node* tail;
    Node* free;
} List;

extern "C" void netReport__FPCce(const char*, ...);
extern "C" void* memcpy(void* dst, const void* src, u32 n);

extern char lbl_8045EEA4[];
extern char lbl_8045EED0[];

extern "C" int fn_8014608C(List* self, u8 arg1, u8 arg2, const void* src, u32 size) {
    Node* node;

    if (size > 0x384) {
        netReport__FPCce(lbl_8045EEA4, size);
        return 0;
    }
    node = self->free;
    self->free = node->next;
    if (node == 0) {
        netReport__FPCce(lbl_8045EED0);
        return 0;
    }
    node->a = arg1;
    node->b = arg2;
    memcpy(node->data, src, size);
    if (self->head != 0) {
        self->head->prev = node;
    }
    node->next = self->head;
    node->prev = 0;
    self->head = node;
    if (self->tail == 0) {
        self->tail = node;
    }
    return 1;
}
