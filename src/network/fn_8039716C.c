#pragma force_active on
extern int lbl_805A1150;

typedef struct Node {
    char pad[0x20];
    struct Node* next;
} Node;

int fn_8039716C(void) {
    Node* n = (Node*)lbl_805A1150;
    int count = 0;
    while (n != 0) {
        n = n->next;
        count++;
    }
    return count;
}
