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
    virtual u8 fn_27_7AB10() const;
};

struct Object {
    char pad[0x24];
    Class_90D8* delegate;
    s32 value;
};

extern "C" u8 fn_27_2876DC(Object* self) {
    s32 value = self->value;
    if (value >= 0) {
        return value;
    }
    return self->delegate->fn_27_7AB10();
}
