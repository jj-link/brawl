#include <types.h>
#pragma force_active on

class IObj {
public:
    u8 pad[4];
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual u32 f7(void*, void*, void*, u32);
    virtual void f8();
    virtual void f9();
};

extern "C" {
IObj* fn_27_8CE44(void*);

u32 fn_27_150AB0(void* self, void* a, void* b, u32 c, void* d) {
    u32 flag = 0;
    if (c == 1)
        flag |= 1;
    char* p = (char*)self;
    IObj* obj = (IObj*)fn_27_8CE44(*(void**)(*(char**)(p + 0x2c) + 8));
    return obj->f7(d, a, b, flag & 0xFF);
}
}
