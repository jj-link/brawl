#include <types.h>
#pragma force_active on

extern "C" {

extern char lbl_80410580[];

class SomeClass {
public:
    virtual void v0() = 0;
    virtual void v1(char* a, int b, void* c) = 0;
    virtual void v2() = 0;
    virtual void v3(char* a, int b, void* c) = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
};

void fn_802D1434(void* arg0, SomeClass* obj) {
    obj->v1(lbl_80410580 + 0x12, 1, arg0);
    obj->v3(lbl_80410580 + 0x1f, 1, *(void**)((char*)arg0 + 0x14));
    obj->v6();
}

}
