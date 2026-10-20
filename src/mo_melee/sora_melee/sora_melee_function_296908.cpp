#include <types.h>
#pragma force_active on

class MyAbstractWork {
public:
    virtual bool isNull() const;          // 1
    virtual s32 getIntWork(u32) const;    // 2
    virtual void setIntWork(s32, u32);    // 3
    virtual void addIntWork(s32, u32);    // 4
    virtual void subIntWork(s32, u32);    // 5
    virtual void mulIntWork(s32, u32);    // 6
    virtual void divIntWork(s32, u32);    // 7
    virtual void incIntWork(u32);         // 8
    virtual void decIntWork(u32);         // 9
    virtual u32 getIntWorkSize();         // 10
    virtual float getFloatWork(u32) const;// 11
    virtual void setFloatWork(float, u32);// 12
    virtual void addFloatWork(float, u32);// 13
    virtual void subFloatWork(float, u32);// 14
    virtual void mulFloatWork(float, u32);// 15
    virtual void divFloatWork(float, u32);// 16
    virtual u32 getFloatWorkSize();       // 17
    virtual void onFlag(u32, u32);        // 18
    virtual void offFlag(u32, u32);       // 19
    virtual void clearFlag(u32);          // 20
    virtual bool isFlag(u32, u32) const;  // 21
    virtual u32 turnOffFlag(u32, u32);    // 22
    virtual u32 getFlagWorkSize();        // 23
    virtual void f23();                   // 24
    virtual void clearWorkAll();          // 25
};

extern "C" void fn_27_296908(MyAbstractWork* work) {
    work->clearWorkAll();
}
