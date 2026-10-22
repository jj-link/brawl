#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct Node {
    int pad0[5];
    u8 pad14;
    u8 f15;
    u8 pad16[6];
    u32 f1c;
    int pad20;
    struct Node* next;
} Node;
typedef struct Q {
    int pad0;
    int f4;
    Node* head;
    Node* tail;
    int count;
    Node* f14;
    Node* f18;
    int f1c;
    u8 pad20[0x24];
    void (*cb)(struct Q*, int, Node*, int);
    int arg;
} Q;
extern u32 fn_8035D728(void);
extern void fn_80387AB0(Q*, Node*);
extern void fn_80388120(Q*, int);

void fn_8038831C(Q* q) {
    u32 now;
    Node* m;
    Node* h;
    Node* n;
    if (q->count == 0) return;
    fn_80388120(q, 0);
    now = fn_8035D728();
    while ((h = q->head) != 0) {
        if (now <= h->f1c + 0x9c4) break;
        h->f15 |= 0x10;
        q->head->f1c = 0x9c4;
        q->head->f15 &= 0xd3;
        q->cb(q, 1, q->head, q->arg);
        n = q->head;
        if (n != 0) {
            q->head = n->next;
            if (q->head == 0) q->tail = 0;
            q->count--;
        }
    }
    if (q->f1c > 0) {
        while (q->count < q->f4 && q->f1c > 0) {
            m = q->f14;
            if (m != 0) {
                q->f14 = m->next;
                if (q->f14 == 0) q->f18 = 0;
                q->f1c--;
            }
            fn_80387AB0(q, m);
        }
    }
    if (q->count == 0) q->cb(q, 2, 0, q->arg);
}
