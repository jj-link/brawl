#pragma force_active on
extern "C" {
extern char lbl_40_data_FCB0[];
void __dla__FPv(void*);
void __dl__FPv(void*);
void __dt__10grYakumonoFv(void*, int);
}

struct Object {
    char pad0[0x3C];
    void* vtable;
    char pad40[0x120];
    char* array;
};

extern "C" void* fn_40_33C30(Object* p, int flag) {
    if (p) {
        p->vtable = lbl_40_data_FCB0;
        char* a = p->array;
        if (a) {
            if (a) {
                __dla__FPv(a - 0x10);
            }
        }
        __dt__10grYakumonoFv(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
