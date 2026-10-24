#pragma force_active on
typedef unsigned short u16;
typedef unsigned long u32;

typedef struct Node {
    u16 flags;
    u16 pad02;
    u32 unk04;
    u32 unk08;
    u32 unkC;
    u32 unk10;
    u32 unk14;
    int unk18;
    u32 unk1C;
    struct Node* next;
    struct Node* prev;
} Node;

void fn_803AFE4C(void* arg0, Node* node) {
    Node* head;
    u16 flags;

    if (*(Node**)((char*)arg0 + 0x15F8) == 0) {
        return;
    }
    flags = node->flags;
    node->unkC = 0;
    node->flags = (u16)(flags & 0xFFFC);
    node->unk10 = 0;
    node->unk18 = -1;
    node->unk1C = 0;
    head = *(Node**)((char*)arg0 + 0x15F8);
    if (node == head) {
        *(Node**)((char*)arg0 + 0x15F8) = node->next;
        return;
    }
    if (node == head->prev) {
        return;
    }
    node->prev->next = node->next;
    node->next->prev = node->prev;
    head = *(Node**)((char*)arg0 + 0x15F8);
    node->next = head;
    node->prev = (*(Node**)((char*)arg0 + 0x15F8))->prev;
    head->prev = node;
    node->prev->next = node;
}
