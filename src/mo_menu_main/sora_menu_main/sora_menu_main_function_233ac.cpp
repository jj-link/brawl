#include <types.h>
#pragma force_active on

extern "C" {
void free__13gfHeapManagerFPv(void*);
void fn_800B8EDC(void*, void*);
void fn_800B8A0C(void*, int);
void fn_2_233AC(void* self);
}

struct VObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v15(void* arg);
};

void fn_2_233AC(void* self) {
    u8* s = static_cast<u8*>(self);
    VObj* obj = *reinterpret_cast<VObj**>(s + 0x654);
    obj->v15(*reinterpret_cast<void**>(*reinterpret_cast<u8**>(s + 0x650) + 0x30));
    void* buf = *reinterpret_cast<void**>(s + 0x674);
    if (buf) {
        free__13gfHeapManagerFPv(buf);
    }
    void* other = *reinterpret_cast<void**>(s + 0x64c);
    void* obj2 = *reinterpret_cast<void**>(s + 0x67c);
    fn_800B8EDC(obj2, *reinterpret_cast<void**>(static_cast<u8*>(other) + 0x218));
    fn_800B8A0C(*reinterpret_cast<void**>(s + 0x67c), 1);
}
