#pragma force_active on
typedef unsigned char u8;

struct Node {
    Node* next;
    char pad0[0x14];
    void* f18;
    char pad1[0x11];
    u8 flag;
};

struct Outer {
    char pad[0x40];
    Node* head;
};

extern "C" void fn_27_232374(Outer* o, void* t) {
    Node* n = o->head;
    while (n != 0) {
        if (n->f18 == t) {
            n->flag = 1;
        }
        n = n->next;
    }
}
