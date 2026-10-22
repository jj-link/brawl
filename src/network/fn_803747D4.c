#pragma force_active on
extern void fn_8035E00C(void *p);
extern void fn_8035A4FC(void *p);

void fn_803747D4(void *arg0) {
    char *self = (char *)arg0;
    void *temp_r0;

    temp_r0 = *(void **)(self + 0x38);
    if (temp_r0 != 0) {
        fn_8035E00C(temp_r0);
    }
    if (*(void **)(self + 0x44) != 0) {
        fn_8035E00C(*(void **)(self + 0x44));
    }
    if (*(void **)(self + 0x50) != 0) {
        fn_8035E00C(*(void **)(self + 0x50));
    }
    if (*(void **)(self + 0x5C) != 0) {
        fn_8035A4FC(*(void **)(self + 0x5C));
    }
    if (*(void **)(self + 0x60) != 0) {
        fn_8035A4FC(*(void **)(self + 0x60));
    }
    if (*(void **)(self + 0x98) != 0) {
        fn_8035A4FC(*(void **)(self + 0x98));
    }
    if (*(void **)(self + 0x9C) != 0) {
        fn_8035A4FC(*(void **)(self + 0x9C));
    }
    fn_8035E00C(arg0);
}
