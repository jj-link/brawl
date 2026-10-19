#include <so/so_array.h>
#pragma force_active on

class OffsetArray : public soArrayVectorCalcInterface {
public:
    virtual void substitution(s32, s32) = 0;
    virtual void onFull() = 0;
    virtual void offFull() = 0;
    virtual void setTopIndex(s32) = 0;
    virtual void setLastIndex(s32) = 0;
    virtual ~OffsetArray() {}
    virtual void method6(s32) = 0;
    virtual void method7(s32) = 0;
    virtual void method8(s32) = 0;
    virtual void method9(s32) = 0;
    virtual void method10(s32) = 0;
    virtual void method11(s32) = 0;
    virtual void method12(s32) = 0;
    virtual void method13(s32) = 0;
    virtual void method14(s32) = 0;
    virtual void method15(s32) = 0;
    virtual void method16(s32) = 0;
    virtual void method17(s32) = 0;
    virtual void method18(s32) = 0;
    virtual void method19(s32) = 0;
    virtual void method20(s32) = 0;
    virtual void method21(s32) = 0;
    virtual void method22(s32) = 0;
    virtual void method23(s32) = 0;
    virtual void method24(s32) = 0;
    virtual void method25(s32) = 0;
    virtual void method26(s32) = 0;
    virtual void method27(s32) = 0;
    virtual void method28(s32) = 0;
    virtual void method29(s32) = 0;
};

extern "C" void fn_78_7914(OffsetArray* self) {
    soArrayVectorCalculator::clear(
        *reinterpret_cast<soArrayVectorCalcInterface*>(
            reinterpret_cast<char*>(self) + 4));
    self->method29(0);
}
