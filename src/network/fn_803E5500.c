#pragma force_active on
typedef unsigned short u16;
typedef unsigned int u32;

extern void fn_803E2458(void *self);

void fn_803E5500(void *arg) {
    u16 i;
    char *self;
    u32 zero;

    self = (char *)arg;
    zero = 0;
    for (i = 0; i < 5; i++) {
        *(u32 *)(self + (u16)i * 0x29C + 0x40) = zero;
        fn_803E2458(self + (u16)i * 0x29C + 0x44);
    }
    *(u32 *)(self + 0xd4c) &= ~1u;
    *(u32 *)(self + 0xd7c) &= ~1u;
    *(u32 *)(self + 0xdac) &= ~1u;
    *(u32 *)(self + 0xddc) &= ~1u;
    *(u32 *)(self + 0xe0c) &= ~1u;
    *(u32 *)(self + 0x161c) = 0;
}
