#include <types.h>
#pragma force_active on

extern "C" char lbl_27_data_25FB0[];
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, long);
extern "C" void __dl__FPv(void*);

class EventMgr {
public:
    virtual void f0();
    virtual void f1(s16);
};

extern "C" void* fn_27_DACFC(void* p, long flag) {
    if (p) {
        *(char**)p = lbl_27_data_25FB0;
        if (*(s16*)((char*)p + 4) != -1) {
            void* sys = getInstance__13soEventSystemFv();
            EventMgr* mgr = (EventMgr*)getManager__13soEventSystemFl(sys, *(s16*)((char*)p + 4));
            mgr->f1(*(s16*)((char*)p + 6));
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}