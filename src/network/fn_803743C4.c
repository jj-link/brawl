#pragma force_active on
typedef struct Obj {
    char pad0[0xC];
    int state;
    int field10;
    int field14;
} Obj;

extern void fn_80378B50(int *, int *);
extern int fn_80377568(void *, int, int);

void fn_803743C4(Obj *self, int arg1, int arg2) {
    int spC;
    int sp8;

    sp8 = arg1;
    spC = arg2;
    self->field14 = 0;
    if (self->state == 4) {
        fn_80378B50(&sp8, &spC);
        fn_80377568(self, sp8, spC);
        self->state = 6;
    }
}
