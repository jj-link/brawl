#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;

extern void fn_8022E8C4(u8, void *, u16, u8, u8, u8);
extern void fn_80232780(void *);

void fn_8023647C(void *arg0, void *arg1) {
    void *sp8;
    void *ptr;
    u8 b;
    u16 a;
    u8 c;
    u8 d;
    u8 e;

    ptr = *(void **)((char *)arg1 + 0xC);
    sp8 = ptr;
    a = *(u16 *)((char *)ptr + 0x4);
    b = (u8)(*(u16 *)((char *)arg1 + 0x6));
    c = *(u8 *)((char *)arg0 + 0x1B);
    d = *(u8 *)((char *)arg0 + 0x13);
    e = *(u8 *)((char *)arg0 + 0x15);
    fn_8022E8C4(b, (char *)ptr + a + 8, *(u16 *)((char *)ptr + 0x2), c, d, e);
    fn_80232780(&sp8);
}
