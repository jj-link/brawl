#include <types.h>
#pragma force_active on

extern "C" {
char lbl_27_data_22D70[];
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
void __dl__FPv(void*);
}

struct Manager {
    virtual void unused0();
    virtual void remove(int);
};

extern "C" void* fn_27_DA90C(char* p, int destroy) {
    if (p) {
        *(void**)p = (void*)lbl_27_data_22D70;
        if (*(s16*)(p + 4) != -1) {
            void* sys = getInstance__13soEventSystemFv();
            Manager* manager = (Manager*)getManager__13soEventSystemFl(sys, *(s16*)(p + 4));
            manager->remove(*(s16*)(p + 6));
        }
        if (destroy > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
