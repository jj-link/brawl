#pragma force_active on
typedef unsigned int u32;

extern void SOInetNtoA(u32 *);

void fn_8038897C(void *arg0) {
    u32 sp8;

    sp8 = *(u32 *)((char *)arg0 + 0x8);
    SOInetNtoA(&sp8);
}
