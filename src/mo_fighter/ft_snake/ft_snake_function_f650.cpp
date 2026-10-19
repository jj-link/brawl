#include <types.h>
#pragma force_active on

class soNull {
    int pad;
};

class soNullable {
public:
    virtual bool isNull() const = 0;
};

class soGeneralWorkAbstract : public soNull, public soNullable {
public:
    virtual s32 getIntWork(u32) const = 0;
    virtual void setIntWork(s32, u32) = 0;
    virtual void addIntWork(s32, u32) = 0;
    virtual void subIntWork(s32, u32) = 0;
    virtual void mulIntWork(s32, u32) = 0;
    virtual void divIntWork(s32, u32) = 0;
    virtual void incIntWork(u32) = 0;
    virtual void decIntWork(u32) = 0;
    virtual u32 getIntWorkSize() = 0;
    virtual float getFloatWork(u32) const = 0;
    virtual void setFloatWork(float, u32) = 0;
    virtual void addFloatWork(float, u32) = 0;
    virtual void subFloatWork(float, u32) = 0;
    virtual void mulFloatWork(float, u32) = 0;
    virtual void divFloatWork(float, u32) = 0;
    virtual u32 getFloatWorkSize() = 0;
    virtual void onFlag(u32, u32) = 0;
    virtual void offFlag(u32, u32) = 0;
    virtual void clearFlag(u32) = 0;
    virtual bool isFlag(u32, u32) const = 0;
    virtual u32 turnOffFlag(u32, u32) = 0;
    virtual u32 getFlagWorkSize() = 0;
    virtual void clearWorkAll() = 0;
};

extern "C" u32 fn_122_F650(soGeneralWorkAbstract* work, u32 flag, u32 index) {
    u32 result = work->isFlag(flag, index);
    if (result == 1) {
        work->offFlag(flag, index);
    }
    return result;
}
