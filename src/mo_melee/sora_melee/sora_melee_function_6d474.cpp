#include <types.h>
#pragma force_active on

extern "C" void* fn_27_6F30C(void*);

class VA {
public:
    virtual void f2();
    virtual void* f3();
    virtual void f4();
    virtual void f5(u32, u32, u32);
};

extern "C" {
void fn_27_6D474(void* self, void* unused, u32 b, u32 c) {
    VA* obj = *(VA**)((char*)self + 0x48);
    void* p = obj->f3();
    p = fn_27_6F30C((char*)p + 0x1c);
    void* q = *(void**)((char*)p + 0x44);
    q = *(void**)((char*)q + 0xd8);
    VA* last = *(VA**)((char*)q + 0x84);
    last->f5(b, c, 0);
}
}
