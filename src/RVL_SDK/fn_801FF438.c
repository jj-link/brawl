#pragma force_active on
struct Node {
    int field0;
    int field1;
    struct Node* next;
};
extern struct Node* lbl_805A0A28;

void fn_801FF438(struct Node* node) {
    node->next = lbl_805A0A28;
    lbl_805A0A28 = node;
}