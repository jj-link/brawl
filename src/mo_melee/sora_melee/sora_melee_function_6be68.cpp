#include <types.h>
#pragma force_active on

extern "C" {
void* getNode__6utListFUl(void*, u32);
void* fn_27_6F30C(void*);
}

class VBase {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void target(u32);
};

extern "C" void fn_27_6BE68(u8* self) {
    u8* node = (u8*)getNode__6utListFUl(self + 0x14, 0);
    while (node != 0) {
        u8* data = *(u8**)(node + 0xc);
        u32 flags = *(u32*)(data + 0x30);
        if ((flags >> 8) & 1) {
            u8* acc = (u8*)fn_27_6F30C(node);
            u8* p = *(u8**)(acc + 0x44);
            p = *(u8**)(p + 0xd8);
            p = *(u8**)(p + 0x44);
            ((VBase*)p)->target(1);
        }
        node = *(u8**)node;
    }
}
