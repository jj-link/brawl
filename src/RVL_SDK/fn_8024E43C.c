#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Node {
    u8 pad[6];
    u16 count;
} Node;

extern u8 lbl_8052CDC0[];
extern char lbl_80483D84[];
extern char lbl_80483D98[];

extern void *fn_8022F8E0(void *);
extern void *fn_8022F8E8(void *);
extern void fn_8022F81C(void *, void *);
extern void fn_80232020(void *);
extern void fn_802319E4(unsigned int, const char *);
extern void fn_80231FB0(void *, int, int);
extern void fn_8024D64C(void *);

void fn_8024E43C(int arg0)
{
    Node *cur;
    Node *next;
    u8 *q;

    q = lbl_8052CDC0 + 0x7C0;
    if (*(u16 *)(lbl_8052CDC0 + 0x7C8) != 0) {
        if (arg0 == 0) {
            fn_80232020(lbl_8052CDC0 + 0x7CC);
            if (lbl_8052CDC0[0] >= 2) {
                fn_802319E4(0x80001, lbl_80483D84);
            }
        } else if (lbl_8052CDC0[0] >= 2) {
            fn_802319E4(0x80001, lbl_80483D98);
        }

        cur = fn_8022F8E0(q);
        while (cur != 0) {
            next = fn_8022F8E8(cur);
            if (arg0 == 0 || cur->count == 0 || (--cur->count) == 0) {
                fn_8022F81C(q, cur);
                cur->count = 0xFFFF;
                fn_8024D64C(cur);
            }
            cur = next;
        }

        if (*(u16 *)(q + 8) != 0) {
            fn_80231FB0(lbl_8052CDC0 + 0x7CC, 4, 1);
        }
    }
}
