#pragma force_active on
#include <types.h>

class soArrayVectorCalcInterface {
public:
    virtual void substitution(s32, s32) = 0;
    virtual void onFull() = 0;
    virtual void offFull() = 0;
    virtual void setTopIndex(s32) = 0;
    virtual void setLastIndex(s32) = 0;
    virtual ~soArrayVectorCalcInterface() { }
};

namespace soArrayVectorCalculator {
    void pop(soArrayVectorCalcInterface& itf, bool isEmpty, s32 capacity, s32 lastIndex);
}

class PrimaryBase {
public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual s32 a3();
    virtual bool a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual s32 a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void a17();
    virtual void a18();
    virtual void a19();
    virtual void a20();
    virtual void a21();
    virtual void a22();
    virtual void a23();
    virtual void a24();
    virtual void a25();
    virtual void a26();
    virtual void a27();
    virtual s32 a28();
    virtual void a29(s32);
};

class Obj : public PrimaryBase, public soArrayVectorCalcInterface { };

extern "C" void fn_96_1E690(Obj& self) {
    soArrayVectorCalcInterface& iface = static_cast<soArrayVectorCalcInterface&>(self);
    soArrayVectorCalculator::pop(iface, self.a4(), self.a13(), self.a28());
    self.a29(self.a3() - 1);
}
