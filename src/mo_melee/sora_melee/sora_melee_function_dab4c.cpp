#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_27_data_25F38[];
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
void __dl__FPv(void*);
}

struct Manager {
    virtual void unused0();
    virtual void remove(s16);
};

extern "C" void* fn_27_DAB4C(void* p, int flag) {
    if (p) {
        s16 id = *(s16*)((char*)p + 4);
        *(void**)p = lbl_27_data_25F38;
        if (id != -1) {
            Manager* manager = (Manager*)getManager__13soEventSystemFl(
                getInstance__13soEventSystemFv(), *(s16*)((char*)p + 4));
            manager->remove(*(s16*)((char*)p + 6));
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
