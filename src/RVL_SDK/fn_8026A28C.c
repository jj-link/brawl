#pragma force_active on
#pragma use_lmw_stmw on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

extern void fn_80269308(void *, u16);
extern void fn_802692BC(void *, u8);
extern void fn_802696FC(void *, u32, int);
extern s32 fn_8026BB2C(void *);

s32 fn_8026A28C(void *arg0) {
    void *buffer = (u8 *)arg0 + 0x1634;
    u16 field4 = *(u16 *)((u8 *)arg0 + 4);
    u16 field2 = *(u16 *)((u8 *)arg0 + 2);
    u32 maskF = 1 << *((u8 *)arg0 + 0xF);
    u32 maskE = 1 << *((u8 *)arg0 + 0xE);

    fn_80269308(buffer, (u16)-64);
    fn_80269308(buffer, 0x11);
    fn_802692BC(buffer, 8);
    fn_80269308(buffer, field4);
    fn_80269308(buffer, field2);
    fn_802692BC(buffer, 3);
    fn_802692BC(buffer, 0);
    fn_802696FC(buffer, maskE, 4);
    fn_802696FC(buffer, maskF, 4);
    fn_802692BC(buffer, 0);
    fn_802692BC(buffer, 1);
    fn_802692BC(buffer, 0x11);
    fn_802692BC(buffer, 1);
    fn_802692BC(buffer, 2);
    fn_802692BC(buffer, 0x11);
    fn_802692BC(buffer, 1);
    return fn_8026BB2C(arg0) < 0 ? -2 : 0;
}
