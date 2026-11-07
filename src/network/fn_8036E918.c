#pragma force_active on
typedef unsigned char u8;

extern void fn_8035E00C(void *p);

void fn_8036E918(u8 *self) {
    if (*(void **)(self + 0xC) != 0) {
        fn_8035E00C(*(void **)(*(u8 **)(self + 0xC) + 0x0));
        *(void **)(*(u8 **)(self + 0xC) + 0x0) = 0;
        fn_8035E00C(*(void **)(*(u8 **)(self + 0xC) + 0x4));
        *(void **)(*(u8 **)(self + 0xC) + 0x4) = 0;
        fn_8035E00C(*(void **)(*(u8 **)(self + 0xC) + 0x8));
        *(void **)(*(u8 **)(self + 0xC) + 0x8) = 0;
        fn_8035E00C(*(void **)(*(u8 **)(self + 0xC) + 0xC));
        *(void **)(*(u8 **)(self + 0xC) + 0xC) = 0;
        fn_8035E00C(*(void **)(*(u8 **)(self + 0xC) + 0x10));
        *(void **)(*(u8 **)(self + 0xC) + 0x10) = 0;
        fn_8035E00C(*(void **)(*(u8 **)(self + 0xC) + 0x14));
        *(void **)(*(u8 **)(self + 0xC) + 0x14) = 0;
        fn_8035E00C(*(void **)(*(u8 **)(self + 0xC) + 0xC8));
        *(void **)(*(u8 **)(self + 0xC) + 0xC8) = 0;
        fn_8035E00C(*(void **)(self + 0xC));
        *(void **)(self + 0xC) = 0;
    }
}
