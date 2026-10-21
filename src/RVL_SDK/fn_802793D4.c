#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *fn_8015C1EC(void *self, u16 idx);

u32 fn_802793D4(u8 *arg0, u32 arg1) {
    u8 *inner = (u8 *)fn_8015C1EC(arg0 + 8, (u16)arg1);
    return *(u32 *)(inner + 4);
}
