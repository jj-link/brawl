#pragma force_active on
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Node {
    u16 flags;
    u16 pad2;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    u32 unk14;
    int unk18;
    u32 unk1C;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct Owner {
    char pad[0x1634];
    Node* head;
} Owner;

void fn_803DA55C(Owner* owner, Node* node) {
    Node* head;
    u16 flags;

    if (owner->head == 0) {
        return;
    }
    flags = node->flags;
    node->unkC = 0;
    node->flags = (u16)(flags & 0xFFFC);
    node->unk10 = 0;
    node->unk18 = -1;
    node->unk1C = 0;
    if (node == owner->head) {
        owner->head = node->next;
        return;
    }
    if (node == owner->head->prev) {
        return;
    }
    node->prev->next = node->next;
    node->next->prev = node->prev;
    head = owner->head;
    node->next = head;
    node->prev = owner->head->prev;
    head->prev = node;
    node->prev->next = node;
}
