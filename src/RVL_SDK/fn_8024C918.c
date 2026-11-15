#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Obj {
    int unk0;
    int state;
    struct Obj *next;
    char pad[0x1C];
    u16 u28;
    char pad2[0x2A];
    void (*cb)(int);
} Obj;

extern void fn_802319E4(int id, const char *msg);
extern void fn_80231FB0(void *p, int a, u16 r);
extern u8 fn_8024144C(u16 a, int b);
extern void fn_8024AED0(void *node, int a, void *b);
extern void fn_8024CB94(void *self, int unused, void *packet);
extern void fn_8024E63C(void *self);
extern char lbl_8048390C[];
extern u8 lbl_8052CDC0[];

void fn_8024C918(Obj *self) {
    Obj *node;
    Obj *next;
    u16 r;
    u8 t;
    void (*cb)(int);

    if (self->state == 2 || self->state == 3 || self->state == 1 || self->state == 5) {
        for (node = self->next; node != 0; node = next) {
            next = node->next;
            fn_8024AED0(node, 3, 0);
        }
        fn_8024E63C(self);
    }

    if (self->state == 4) {
        cb = self->cb;
        if (cb != 0) {
            self->cb = 0;
            cb(2);
            if (lbl_8052CDC0[0] >= 2) {
                fn_802319E4(0x80001, lbl_8048390C);
            }
            for (node = self->next; node != 0; node = next) {
                next = node->next;
                fn_8024AED0(node, 3, 0);
            }
        }
        if (self->next == 0) {
            t = fn_8024144C(self->u28, 0x13);
            if (t == 1) {
                r = 0x1E;
                self->state = 5;
            } else if (t == 0) {
                self->state = 5;
                r = 0xFFFF;
            } else {
                r = 1;
            }
            if (r != 0xFFFF) {
                fn_80231FB0((char *)self + 0x10, 2, r);
            }
        } else {
            fn_8024CB94(self, 0, 0);
        }
    }
}
