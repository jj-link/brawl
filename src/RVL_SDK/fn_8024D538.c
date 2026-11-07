#include <string.h>
#pragma force_active on
typedef struct Node {
    char pad[8];
    struct Node *next;
    char rest[0x70];
} Node;
typedef struct State {
    unsigned char a, b;
    char pad[0x176];
    Node nodes[10];
    char gap[0x160];
    Node *head, *tail;
    char pad2[2];
    unsigned short value;
    char rest[0x2c];
} State;
extern State lbl_8052CDC0;
void fn_8024D538(void) {
    int i;
    memset(&lbl_8052CDC0, 0, 0x7e8);
    for (i = 0; i < 9; i++)
        lbl_8052CDC0.nodes[i].next = &lbl_8052CDC0.nodes[i + 1];
    lbl_8052CDC0.head = &lbl_8052CDC0.nodes[0];
    lbl_8052CDC0.tail = &lbl_8052CDC0.nodes[9];
    lbl_8052CDC0.b = 0;
    lbl_8052CDC0.value = 2;
    lbl_8052CDC0.a = 0;
}