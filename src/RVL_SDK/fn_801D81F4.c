#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;

void fn_801D81F4(void *arg0) {
    *(u16 *)((char *)arg0 + 0x1A0) = 0;
    *(u16 *)((char *)arg0 + 0x1A2) = 0;
    if ((u32)arg0 == *(u32 *)0x800000D8) {
        *(u32 *)0x800000D8 = 0;
    }
}
