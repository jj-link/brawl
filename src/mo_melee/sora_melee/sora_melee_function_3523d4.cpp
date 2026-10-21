#include <types.h>
#pragma force_active on

class soObjVt {
public:
    virtual void f0() = 0;
    virtual void f1() = 0;
    virtual soObjVt* f2() = 0;
    virtual void f3() = 0;
    virtual void f4() = 0;
};

extern "C" void fn_27_353C20(void* a, void* b, u32 c, u32 d, u32 e, u32 f, void* g);

extern "C" {
bool fn_27_3523D4(void* unused, void* p1, u8* p2, u32 p3, u32 p4, u32 p5, u32 p6) {
    soObjVt* obj = *(soObjVt**)(*(u8**)(p2 + 0xD8) + 0x18);
    void* sub = *(void**)(*(u8**)(p2 + 0x8) + 0x28);
    obj = obj->f2();
    soObjVt* res = obj->f2();
    fn_27_353C20(p1, sub, p3, p4, p5, p6, res);
    return true;
}
}
