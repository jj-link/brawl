#pragma force_active on
extern int closesocket(int);
extern void fn_8035C2D8(int, int);
extern void fn_8035E00C(void *);
extern void fn_8037B5E4(void *);
extern void fn_8037BE74(void);
extern void fn_8037BE78(int);
extern int fn_8037F1AC(void *);
extern void fn_8037F1B4(int *);
extern void fn_8037FA44(void *);
extern int lbl_805A106C;
extern int lbl_805A1070;

int fn_8037C5AC(void *arg0) {
    char *self;
    int idx;
    int old;
    self = (char *)arg0;
    if (arg0 == 0) {
        return 0;
    }
    if (*(int *)self == 0) {
        return 0;
    }
    idx = *(int *)(self + 4);
    if (idx < 0) {
        return 0;
    }
    if (idx >= lbl_805A1070) {
        return 0;
    }
    fn_8037BE74();
    fn_8035E00C(*(void **)(self + 0x14));
    fn_8035E00C(*(void **)(self + 0x18));
    fn_8035E00C(*(void **)(self + 0x24));
    fn_8035E00C(*(void **)(self + 0x2c));
    fn_8035E00C(*(void **)(self + 0x12c));
    fn_8035E00C(*(void **)(self + 0x188));
    if (*(int *)(self + 0x4c) != -1) {
        fn_8035C2D8(*(int *)(self + 0x4c), 2);
        closesocket(*(int *)(self + 0x4c));
    }
    fn_8037B5E4(self + 0x54);
    fn_8037B5E4(self + 0x78);
    fn_8037B5E4(self + 0x9c);
    fn_8037B5E4(self + 0xc0);
    fn_8037B5E4(self + 0xe4);
    if (*(int *)(self + 0x164) != 0) {
        fn_8037FA44(self);
    }
    if (*(int *)(self + 0x160) != 0 && fn_8037F1AC(*(void **)(self + 0x160)) != 0) {
        fn_8037F1B4(*(int **)(self + 0x160));
        *(int *)(self + 0x160) = 0;
    }
    if (*(int *)(self + 0x198) != 0) {
        if (*(int *)(self + 0x1a4) != 0) {
            ((void (*)(void *, void *)) *(int *)(self + 0x1a4))(self, self + 0x190);
        }
        *(int *)(self + 0x198) = 0;
    }
    *(int *)self = 0;
    old = lbl_805A106C;
    lbl_805A106C = old - 1;
    fn_8037BE78(old);
    return 1;
}