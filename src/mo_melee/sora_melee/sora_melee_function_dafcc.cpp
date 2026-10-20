#include <types.h>
#pragma force_active on
extern "C" {
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
void __dl__FPv(void*);
extern char lbl_27_data_26078[];
}

struct Mgr {
    virtual void f0();
    virtual void f1(s16);
};

extern "C" void* fn_27_DAFCC(char* p, int destroy) {
    if (p) {
        *(void**)p = lbl_27_data_26078;
        if (*(short*)(p + 4) != -1) {
            void* sys = getInstance__13soEventSystemFv();
            Mgr* m = (Mgr*)getManager__13soEventSystemFl(sys, *(short*)(p + 4));
            m->f1(*(short*)(p + 6));
        }
        if (destroy > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
