#pragma force_active on
struct Node {
    int pad0;
    struct Node* next;
    char pad8[0x14];
    int val;
};

struct Obj {
    int pad0;
    struct Node* head;
    char pad8[0x14];
    int total;
};

int fn_8027C854(struct Obj* o) {
    struct Node* n = o->head;
    int sum = o->total;
    while (n != 0) {
        sum += n->val;
        n = n->next;
    }
    return sum;
}
