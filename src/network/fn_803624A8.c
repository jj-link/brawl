#pragma force_active on
extern void fn_80362E0C(void *);
extern void fn_8035E00C(void *);
extern void fn_8037EFFC(int);

int fn_803624A8(void *arg0) {
    char *self = (char *)arg0;
    void *temp = *(void **)(self + 0x14);
    if (temp != 0) {
        fn_80362E0C(temp);
    }
    if (*(void **)(self + 0x18) != 0) {
        fn_8035E00C(*(void **)(self + 0x18));
    }
    if (*(int *)(self + 0x1c) != 0) {
        fn_8037EFFC(*(int *)(self + 0x1c));
    }
    fn_8035E00C(arg0);
    return 1;
}