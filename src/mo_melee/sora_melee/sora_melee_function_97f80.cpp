#include <ec/ec_trace_mgr.h>
#pragma force_active on

class soStopModuleImpl {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void cancelHitStop();
    virtual void setOtherStop();
    virtual void cancelOtherStop();
    virtual void setLinkStop();
    virtual int isStop();
    virtual int isSpecialStop();
};

struct Flags { unsigned char paused : 1; unsigned char rest : 7; };

extern "C" {
    void* fn_27_97E60();
    void fn_80060B1C(void*, u32, u32);
    void fn_80060BB8(void*, u32, u32);
}
extern void* g_ecMgr;

extern "C" void fn_27_97F80(u8* self) {
    self[0x135] = (u8)(self[0x135] & 0xFFFFFFBF);
    soStopModuleImpl* o = *(soStopModuleImpl**)(*(u8**)(*(u8**)(self + 0x44) + 0xd8) + 0x44);
    if (o->isSpecialStop() != 0) {
        u32 b = self[0x135];
        if (!((b >> 5) & 1U) && ((b >> 7) & 1U) == 1U) {
            fn_80060BB8(g_ecMgr, *(u32*)(self + 0x48) | 2, 0xFFFF02);
            ((ecTraceMgr*)((u8*)fn_27_97E60() + 0x98))->pauseGroup(false, *(u32*)(self + 0x48) | 2, 0xFFFFFFFF);
            ((Flags*)(self + 0x135))->paused = 0;
        }
    } else {
        o = *(soStopModuleImpl**)(*(u8**)(*(u8**)(self + 0x44) + 0xd8) + 0x44);
        if (o->isStop() != 0 || (((u32)self[0x135] >> 5) & 1U) == 1U) {
            if ((((u32)self[0x135] >> 7) & 1U) == 0U) {
                fn_80060B1C(g_ecMgr, *(u32*)(self + 0x48) | 2, 0xFFFF02);
                ((ecTraceMgr*)((u8*)fn_27_97E60() + 0x98))->pauseGroup(true, *(u32*)(self + 0x48) | 2, 0xFFFFFFFF);
                self[0x135] = (u8)(self[0x135] | 0x80);
            }
        } else if ((((u32)self[0x135] >> 7) & 1U) == 1U) {
            fn_80060BB8(g_ecMgr, *(u32*)(self + 0x48) | 2, 0xFFFF02);
            ((ecTraceMgr*)((u8*)fn_27_97E60() + 0x98))->pauseGroup(false, *(u32*)(self + 0x48) | 2, 0xFFFFFFFF);
            ((Flags*)(self + 0x135))->paused = 0;
        }
    }
}