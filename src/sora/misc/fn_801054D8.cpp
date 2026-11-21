#pragma force_active on
struct Object {
    char pad0[0x2C];
    int field2C;
    char pad30[0xAC];
    int fieldDC;
    char padE0[0x21C];
    unsigned char field2FC;
};
struct Callbacks {
    char pad[0x18];
    void (*callback)(Object *);
    char tail[0x24];
};
extern "C" {
extern void fn_8010535C(void *, void *);
extern const Callbacks lbl_804092A0;
void fn_801054D8(Object *arg0) {
    if (arg0->fieldDC != 0) {
        if (arg0->field2FC == 0) {
            fn_8010535C(arg0, arg0->field2C == 0 ? (void *)0 : (void *)2);
        }
        arg0->fieldDC = 3;
        void (*fn)(Object *) = lbl_804092A0.callback;
        if (fn != 0) fn(arg0);
    }
}
}
