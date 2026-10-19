#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);

struct UnkBase {
    u32 m_unk0;
};

class UnkObj : public UnkBase {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    u8 m_pad[0xAC4];
};

extern "C" UnkObj* fn_1_1077C(UnkObj*);

extern "C" void* fn_1_10720() {
    UnkObj* obj = (UnkObj*)__nw__FUlQ25Heaps8HeapType(sizeof(UnkObj), 0x2E);
    if (obj) {
        obj = fn_1_1077C(obj);
    }
    obj->v4();
    return obj;
}
