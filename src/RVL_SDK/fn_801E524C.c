#pragma force_active on
#pragma optimization_level 1
#pragma scheduling off

extern void fn_801D7FCC(void *p);
extern void fn_801D81F4(void *p);
extern void fn_801DD2A0(unsigned int);

typedef void (*Callback)(int, void *);

typedef struct {
    int a;
    int b;
    Callback callback;
    unsigned int flags;
    unsigned char pad[0x30];
} Control;

extern Control lbl_804DE270[3];

void fn_801E524C(int arg0, void *arg1) {
    unsigned char sp8[0x2C0];
    int idx;
    Control *c;
    Callback fn;

    idx = (arg0 - 0xB) / 3;
    fn_801DD2A0(0x500000u >> (idx * 3));
    c = &lbl_804DE270[idx];
    fn = c->callback;
    c->flags &= ~8u;
    if (fn != 0) {
        fn_801D81F4(sp8);
        fn_801D7FCC(sp8);
        c->callback = 0;
        fn(idx, arg1);
        fn_801D81F4(sp8);
        fn_801D7FCC(arg1);
    }
}
