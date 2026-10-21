#include <types.h>
#pragma force_active on

extern "C" void fn_27_1DB0EC(void*);
extern "C" void fn_27_23313C(void*, void*, u32, u32);
extern "C" u32 g_stTriggerMng;

class fnVirtObj {
public:
    virtual void* v0();
    virtual void* v1();
    virtual void* v2();
    virtual void* v3();
    virtual void* v6(u32);
};

extern "C" void fn_41_33048(u8* self, u32 a2, u8* a3, u32 a4, u32 a5, u32 a6) {
    fn_27_1DB0EC(self + 0xc);
    if (a6 == 0 && g_stTriggerMng != 0) {
        u32 r31 = *(u32*)(self + 0x34);
        u8* p = *(u8**)(self + 0x6c);
        p = *(u8**)(p + 0xd8);
        p = *(u8**)(p + 0x64);
        void* r3 = reinterpret_cast<fnVirtObj*>(p)->v6(0x10000005);
        fn_27_23313C(r3, *(void**)(a3 + 0xc), r31, 0x28);
    }
}
