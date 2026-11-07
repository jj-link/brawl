#pragma force_active on
struct Node {
    Node* a;
    Node* next;
};
struct Obj {
    char pad[0x40];
    Node* list;
};

extern "C" void fn_27_75C9C(Obj* self, Node* n) {
    Node* p = self->list;
    Node* x;
    Node** pp;
    x = p->next;
    if (x) {
        p = x->next;
        if (p) {
            x = p->next;
            if (x) {
                p = x->next;
                if (p) {
                    x = p->next;
                    if (x) {
                        pp = &x->next;
                        goto loop;
                    }
                    p->next = n;
                } else x->next = n;
            } else p->next = n;
        } else x->next = n;
    } else p->next = n;
    return;
loop:
    for (;;) {
        x = *pp;
        if (x) {
            p = x->next;
            if (p) {
                x = p->next;
                if (x) {
                    p = x->next;
                    if (p) {
                        x = p->next;
                        if (x) { pp = &x->next; continue; }
                        p->next = n;
                    } else x->next = n;
                } else p->next = n;
            } else x->next = n;
        } else *pp = n;
        return;
    }
}
