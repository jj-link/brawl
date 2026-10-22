#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

extern "C" {
extern s32 lbl_805A0360;
u32 fn_80111C54(u16 *p, u32 x);
void fn_80112E14(s32 self, void *src, s32 *val);

void fn_80135890(void *arg0) {
    u8 *obj_bytes = (u8 *)arg0;
    u16 *p;
    u32 spC;
    u32 tmp;
    u16 *h;
    s32 obj;

    tmp = 0xFFFF;
    p = *(u16 **)(obj_bytes + 0x15C);
    obj = lbl_805A0360;
    h = (u16 *)&tmp;
    h[0] = *p;
    h[1] = (u16)fn_80111C54(p, *(u32 *)(obj_bytes + 0x154));
    spC = tmp;
    fn_80112E14(obj, arg0, (s32 *)&spC);
    obj_bytes[0x71] |= 4;
}
}
