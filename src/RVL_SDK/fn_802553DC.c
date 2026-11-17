#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef struct {
    u16 event;
    u16 len;
    u16 offset;
    u16 layer_specific;
} BT_HDR;
extern void fn_80254D68(void *, s32, void *);
void fn_802553DC(void *a3, s32 a4, BT_HDR *p) {
    u16 i;
    u8 *src;
    u8 *dst;
    u16 m;
    u8 *q;
    if (p->offset < 0x10) {
        src = (u8 *)(p + 1) + p->offset + p->len - 1;
        dst = (u8 *)(p + 1) + 0x10 + p->len - 1;
        for (i = 0; i < p->len; i++) {
            *dst-- = *src--;
        }
        p->offset = 0x10;
    }
    p->offset -= 2;
    q = (u8 *)(p + 1) + p->offset;
    q[0] = (u8)((a4 ? 2 : 0) | 0x21);
    q[1] = (u8)((p->len << 1) | 1);
    p->len += 2;
    fn_80254D68(a3, 0, p);
}
