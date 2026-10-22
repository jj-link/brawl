#pragma force_active on
typedef struct Obj {
    char pad0[4];
    int unk4;
    char pad8[0x6C];
    int unk74;
    int unk78;
} Obj;

extern int fn_8020CAD4(void);
extern int fn_8020CAEC(void);
extern void fn_80215008(int, unsigned int, void (*)(void), void *);
extern void fn_8020B1F4(void);

int fn_8020B268(int *arg0, int arg1, int arg2, Obj *arg3) {
    if (fn_8020CAD4() == 0) {
        return -0x80;
    }
    arg3->unk4 = arg2;
    arg3->unk74 = arg1;
    arg3->unk78 = 0;
    fn_80215008(*arg0, ((unsigned int)arg3 + 0x53) & ~0x1F, fn_8020B1F4, arg3);
    return fn_8020CAEC();
}
