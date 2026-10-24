#pragma force_active on
#pragma optimization_level 1
#pragma scheduling off

extern void fn_801D7FCC(void *p);
extern void fn_801D81F4(void *p);

typedef void (*Callback)(int, void *);

typedef struct {
    Callback callback;
    unsigned char pad[0x3C];
} Control;

extern Control lbl_804DE270[3];

void fn_801E4F7C(int arg0, void *arg1) {
    unsigned char sp8[0x2C0];
    int idx;
    unsigned int *regs;
    unsigned int base;
    Callback fn;

    idx = (arg0 - 9) / 3;
    regs = (unsigned int *)(idx * 0x14);
    base = 0xCD000000;
    regs = (unsigned int *)(base + (unsigned int)regs);
    regs[0x6800 / 4] = (regs[0x6800 / 4] & 0x7F5) | 2;
    fn = lbl_804DE270[idx].callback;
    if (fn != 0) {
        fn_801D81F4(sp8);
        fn_801D7FCC(sp8);
        fn(idx, arg1);
        fn_801D81F4(sp8);
        fn_801D7FCC(arg1);
    }
}
