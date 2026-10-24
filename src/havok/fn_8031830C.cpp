#include <types.h>
#pragma force_active on

struct Obj {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4(u16);
};

extern "C" void fn_8031830C(char* self, Obj* obj) {
    char* p = self;
    int i = 0;
    for (; i < *(unsigned char*)(self + 2); p += 8, i++) {
        if (*(u16*)(p + 6) != 0xffff) {
            obj->slot4(*(u16*)(p + 6));
        }
    }
    *(unsigned char*)(self + 2) = 0;
    *(unsigned char*)(self + 0) = 0;
    *(unsigned char*)(self + 1) = 0;
}
