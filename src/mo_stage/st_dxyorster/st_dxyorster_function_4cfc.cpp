#include <types.h>
#pragma force_active on

struct StageData {
    float f00;
    float f04;
    float f08;
    float f0c;
    s32 w10[2];
    s32 w18;
    s32 w1c;
    s32 w20[2];
    s32 w28;
    u16 h2c;
    u16 h2e;
    u8 b30;
    u8 b31;
    u8 b32;
    u8 b33;
    u8 b34;
    u8 b35;
    u8 b36;
    u8 b37;
    u8 b38;
    u8 b39;
    u8 b3a;
    s32 w3c;
    s32 w40[2];
    s32 w48;
    float f4c;
    s32 w50;
    s32 w54;
    s32 w58;
    s32 w5c;
    float f60;
    float f64;
    float f68;
    s32 w6c;
    s32 w70;
    s32 w74;
    s32 w78;
    float f7c;
    s32 w80[2];
    s32 w88;
    s32 w8c[2];
    float f94;
    s32 w98;
    u8 b9c;
};

class StageDataOwner {
public:
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual StageData* getData(u32 index);
};

extern "C" void fn_76_4CFC(StageDataOwner* self, u32 from, u32 to) {
    StageData* src = self->getData(from);
    StageData* dst = self->getData(to);
    *dst = *src;
}
