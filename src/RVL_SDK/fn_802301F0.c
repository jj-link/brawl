#pragma force_active on
typedef struct N {
    struct N *prev;
    struct N *next;
    int a;
    int val;
    int b;
    short c;
    unsigned char flag;
} N;
typedef struct L {
    N *head;
    N *tail;
    int total;
} L;

void fn_802301F0(L *l, N *n) {
    N *p;
    if (n == 0) return;
    if (n->flag == 0) return;
    if (l->head == 0) {
    empty:
        return;
    }
    {
        p = n->prev;
        if (p != 0) {
            p->val = p->val + n->val;
        } else {
            l->total = l->total - n->val;
        }
        if (l->head == n) {
            p = n->prev;
            l->head = p;
            if (p != 0) p->next = 0;
            if (l->tail == n) l->tail = 0;
        } else if (l->tail == n) {
            p = n->next;
            l->tail = p;
            if (p != 0) p->prev = 0;
        } else {
            p = n->prev;
            if (p == 0) goto empty;
            if (p->next == n) {
                p->next = n->next;
            } else {
                return;
            }
            p = n->next;
            if (p != 0 && p->prev == n) {
                p->prev = n->prev;
            } else {
                return;
            }
        }
        n->next = 0;
        n->prev = 0;
        n->val = 0x80000000;
        n->flag = 0;
    }
}
