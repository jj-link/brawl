#pragma force_active on
typedef unsigned char u8;

extern void fn_8035E00C(void *p);
extern void fn_8036E918(void *p);

void fn_80370400(u8 *self) {
    if (*(void **)(self + 0x8) != 0) {
        fn_8035E00C(*(void **)(*(u8 **)(self + 0x8) + 0x8));
        *(void **)(*(u8 **)(self + 0x8) + 0x8) = 0;
        fn_8035E00C(*(void **)(*(u8 **)(self + 0x8) + 0xC));
        *(void **)(*(u8 **)(self + 0x8) + 0xC) = 0;
        fn_8035E00C(*(void **)(self + 0x8));
        *(void **)(self + 0x8) = 0;
    }
    fn_8036E918(self);
    fn_8035E00C(*(void **)(self + 0x10));
    *(void **)(self + 0x10) = 0;
    fn_8035E00C(*(void **)(self + 0x18));
    *(void **)(self + 0x18) = 0;
}
