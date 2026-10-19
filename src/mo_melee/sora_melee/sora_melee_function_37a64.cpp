#include <types.h>
#pragma force_active on

extern "C" void fn_8015BFB4(void*, void*);

class InnerClass {
public:
    virtual void* v0() = 0;
    virtual void* v1() = 0;
    virtual void* v2() = 0;
    virtual void* v3() = 0;
};

extern "C" void fn_27_37A64(void* self, void* unused, void* arg2) {
    InnerClass* inner = *(InnerClass**)((char*)self + 8);
    void* result = inner->v1();
    fn_8015BFB4((char*)result + 0x40, arg2);
    *(u8*)((char*)self + 0x12) = 1;
}
