#include <types.h>
#pragma force_active on

// Local view of the work-object vtable, declared without bodies so that
// nothing else is emitted into this file. Only the slot layout matters here:
// onFlag must be at vtable slot 16 (0x40). In this file, a class with no bases
// places onFlag two slots past its declared index, so two fewer virtuals are
// declared before it. This matches the original code; it does not confirm the
// real class layout.
class soGeneralWorkSimple {
public:
    virtual s32 getIntWork(u32 index) const;
    virtual void setIntWork(s32 value, u32 index);
    virtual void addIntWork(s32 value, u32 index);
    virtual void subIntWork(s32 value, u32 index);
    virtual void mulIntWork(s32 value, u32 index);
    virtual void divIntWork(s32 value, u32 index);
    virtual void incIntWork(u32 index);
    virtual void decIntWork(u32 index);
    virtual float getFloatWork(u32 index) const;
    virtual void setFloatWork(float value, u32 index);
    virtual void addFloatWork(float value, u32 index);
    virtual void subFloatWork(float value, u32 index);
    virtual void mulFloatWork(float value, u32 index);
    virtual void divFloatWork(float value, u32 index);
    virtual void onFlag(u32 flag, u32 index);
    virtual void offFlag(u32 flag, u32 index);
    virtual void clearFlag(u32 index);
    virtual bool isFlag(u32 flag, u32 index) const;
    virtual u32 turnOffFlag(u32 flag, u32 index);
    virtual u32 getFlagWorkSize();
    virtual void clearWorkAll();
};

// ft_wolf: forward to the virtual onFlag (vtable slot 16).
extern "C" void fn_125_10B5C(soGeneralWorkSimple* work, u32 flag, u32 index) {
    work->onFlag(flag, index);
}
