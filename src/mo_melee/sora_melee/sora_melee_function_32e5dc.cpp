#include <types.h>
#pragma force_active on

class Obj {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual s32 slot6();
};

extern "C" void* __dynamic_cast(void*, long, const void*, const void*, long);
extern "C" void* fn_27_32E680(void* a, void* b, void* c);
extern char lbl_27_data_88930[];
extern char lbl_27_data_C938[];

extern "C" s32 fn_27_32E5DC(void* a, Obj* b, void* c) {
    if (b->slot6() == 0xD) {
        void* p = __dynamic_cast(b, 0, lbl_27_data_88930, lbl_27_data_C938, 0);
        if (p == 0) {
            return 0;
        }
        return (s32)fn_27_32E680(a, p, c);
    }
    return 0;
}
