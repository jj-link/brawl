#pragma force_active on
typedef struct E {
    unsigned char act;
    char p1[3];
    int a;
    struct E *prev;
    struct E *next;
    struct P2 *parent;
    char pad[0x4];
    char list[0x58];
    int cnt;
} E;
typedef struct P2 {
    unsigned char act;
    int state;
    struct E *head;
    struct E *tail;
    char pad[0x18];
    unsigned short u28;
    char pad2[0x2E];
    unsigned short u58;
} P2;
extern void fn_8022F0E0();
extern void fn_8022F77C(void *);
extern void fn_80231FB0(void *, int, unsigned short);
extern void fn_80232020(void *);
extern unsigned char fn_8024144C(unsigned short, int);
extern struct { char pad[0x7B0]; E *head; E *tail; } lbl_8052CDC0;

void fn_8024FA74(E *e) {
    P2 *p = e->parent;
    if (e->act != 0) {
        e->act = 0;
        fn_80232020(e->list);
        while (e->cnt != 0) {
            fn_8022F77C(&e->cnt);
            fn_8022F0E0();
        }
        e->parent = 0;
        if (p->head == e) {
            p->head = e->prev;
            if (p->head != 0) p->head->next = 0;
        } else if (p->tail == e) {
            p->tail = e->next;
            p->tail->prev = 0;
        } else {
            e->next->prev = e->prev;
            e->prev->next = e->next;
        }
        if (lbl_8052CDC0.head == 0) {
            lbl_8052CDC0.head = e;
            lbl_8052CDC0.tail = e;
            e->prev = 0;
            e->next = 0;
        } else {
            e->prev = 0;
            e->next = lbl_8052CDC0.tail;
            lbl_8052CDC0.tail->prev = e;
            lbl_8052CDC0.tail = e;
        }
        if (p->act != 0 && p->state == 4 && p->head == 0) {
            unsigned short r = p->u58;
            if (r == 0) {
                unsigned char t = fn_8024144C(p->u28, 0x13);
                if (t == 1) {
                    r = 0x1E;
                    p->state = 5;
                } else if (t == 0) {
                    p->state = 5;
                    r = 0xFFFF;
                } else {
                    r = 1;
                }
            }
            if (r != 0xFFFF) fn_80231FB0((char *)p + 0x10, 2, r);
        }
    }
}
