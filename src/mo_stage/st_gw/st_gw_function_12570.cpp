#pragma force_active on
extern "C" {
void __dl__FPv(void*);
void fn_63_10D0C(void*, int);
extern char lbl_63_data_52D0[];

struct Obj {
    unsigned char pad0[0x3c];
    void* vtable;
    unsigned char pad1[0x160];
    void* owned;
};

void* fn_63_12570(void* a, int b) {
    Obj* p = (Obj*)a;
    if (p) {
        if (p) {
            void* sub = p->owned;
            p->vtable = lbl_63_data_52D0;
            if (sub) {
                __dl__FPv(sub);
            }
            p->owned = 0;
            fn_63_10D0C(p, 0);
        }
        if (b > 0) {
            __dl__FPv(p);
        }
    }
    return a;
}
}
