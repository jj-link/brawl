#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct Node {
    char pad[8];
    struct Node *next;
};

extern struct Node *fn_8024E73C(void *);
extern void fn_802319E4(u32, const char *);
extern void fn_8024AED0(struct Node *, u8, u8 *);
extern void *memcpy(void *, const void *, u32);
extern u8 lbl_8052CDC0[];
extern char lbl_804838E4[];

void fn_8024C738(void *a, int unused, int b) {
    u8 buf[8];
    struct Node *n;
    struct Node *next;

    buf[6] = (u8)b;
    memcpy(buf, a, 6);
    n = fn_8024E73C(a);
    if (n == 0) {
        if (lbl_8052CDC0[0] >= 2) {
            fn_802319E4(0x80001, lbl_804838E4);
        }
    } else {
        n = n->next;
        while (n != 0) {
            next = n->next;
            fn_8024AED0(n, (u8)(b == 0 ? 7 : 8), buf);
            n = next;
        }
    }
}
