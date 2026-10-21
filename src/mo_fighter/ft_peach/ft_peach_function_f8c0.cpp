#include <types.h>
#pragma force_active on

class soArrayVectorCalcInterface;

class soArrayVectorCalculator {
public:
    void shift(soArrayVectorCalcInterface& iface, bool b, s32 l1, s32 l2);
};

class FtPeachObj {
public:
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual s32 v3();
    virtual void* v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
    virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12();
    virtual bool v13();
    virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21();
    virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25();
    virtual void v26();
    virtual s32 v27();
    virtual void v28();
    virtual void v29(s32 x);
};

extern "C" void fn_103_F8C0(void* self) {
    FtPeachObj* o = (FtPeachObj*)self;
    soArrayVectorCalculator* calc = (soArrayVectorCalculator*)((char*)self + 4);
    s32 unused;
    calc->shift(*(soArrayVectorCalcInterface*)o->v4(), o->v13(), o->v27(), unused);
    s32 n = o->v3();
    o->v29(n - 1);
}
