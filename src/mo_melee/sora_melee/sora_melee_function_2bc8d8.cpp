#include <types.h>
#pragma force_active on

struct Class_90D8_base { char pad[0x8]; };
class Class_90D8 : public Class_90D8_base {
public:
    virtual void fn_27_7B274();
    virtual void fn_27_7AC18();
    virtual void fn_27_7AC28();
    virtual void fn_27_7AB50();
    virtual void fn_27_7B2EC();
    virtual u8 fn_27_7AB10(u32);
    virtual void fn_27_7AD2C(u8, u16);
    virtual void fn_27_7AEDC();
    virtual void fn_27_7B22C();
    virtual void fn_27_7AC38();
    virtual void fn_27_7ADE8();
    virtual s32 fn_27_7AF98(s32, u32, s32);
};

class Self : public Class_90D8_base {
public:
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual u8 getGroup(u32);
    virtual void setGroup(u8, u16);
    u32 pad[6];
    Class_90D8* inner;
};

extern "C" s32 fn_27_2BC8D8(Self* self, s32 a, u32 b, s32 c) {
    u8 saved = self->inner->fn_27_7AB10(0);
    Class_90D8* inner = self->inner;
    u8 group = self->getGroup(0);
    inner->fn_27_7AD2C(group, 0xFF);
    s32 result = self->inner->fn_27_7AF98(a, b, c);
    self->inner->fn_27_7AD2C(saved, 0xFF);
    return result;
}
