#pragma force_active on
typedef unsigned short u16;
typedef unsigned long u32;
typedef long s32;

typedef struct Node {
    u16 flags;
    u16 pad2;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    u32 unk14;
    s32 unk18;
    u32 unk1C;
    struct Node* next;
    struct Node* prev;
} Node;

void fn_803DA4CC(char* arg0, Node* arg1) {
    Node* head = *(Node**)(arg0 + 0x1630);
    Node* h;
    if (head == 0) {
        return;
    }
    arg1->unkC = 0;
    arg1->flags = (u16)(arg1->flags & 0xFFFC);
    arg1->unk10 = 0;
    arg1->unk18 = -1;
    arg1->unk1C = 0;
    head = *(Node**)(arg0 + 0x1630);
    if (arg1 == head) {
        *(Node**)(arg0 + 0x1630) = arg1->next;
        return;
    }
    if (arg1 == head->prev) {
        return;
    }
    arg1->prev->next = arg1->next;
    arg1->next->prev = arg1->prev;
    h = *(Node**)(arg0 + 0x1630);
    arg1->next = h;
    arg1->prev = (*(Node**)(arg0 + 0x1630))->prev;
    h->prev = arg1;
    arg1->prev->next = arg1;
}
