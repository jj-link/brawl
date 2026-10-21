#pragma force_active on
typedef signed int s32;
typedef unsigned char u8;

class Main {
public:
    virtual void v0() = 0;    // idx0
    virtual void v1() = 0;    // idx1
    virtual void v2() = 0;    // idx2
    virtual s32 v3() = 0;     // idx3  -> 0x14 size
    virtual bool v4() = 0;    // idx4  -> 0x18 isEmpty
    virtual void v5() = 0;    // idx5
    virtual void v6() = 0;    // idx6
    virtual void v7() = 0;    // idx7
    virtual void v8() = 0;    // idx8
    virtual void v9() = 0;    // idx9
    virtual void v10() = 0;   // idx10
    virtual void v11() = 0;   // idx11
    virtual void v12() = 0;   // idx12
    virtual s32 v13() = 0;    // idx13 -> 0x3c capacity
    virtual void v14() = 0;   // idx14
    virtual void v15() = 0;   // idx15
    virtual void v16() = 0;   // idx16
    virtual void v17() = 0;   // idx17
    virtual void v18() = 0;   // idx18
    virtual void v19() = 0;   // idx19
    virtual void v20() = 0;   // idx20
    virtual void v21() = 0;   // idx21
    virtual void v22() = 0;   // idx22
    virtual void v23() = 0;   // idx23
    virtual void v24() = 0;   // idx24
    virtual void v25() = 0;   // idx25
    virtual void v26() = 0;   // idx26
    virtual void v27() = 0;   // idx27
    virtual s32 v28() = 0;    // idx28 -> 0x78 getLastIndex
    virtual void v29(s32) = 0;// idx29 -> 0x7c setSize
};

extern "C" void pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll(Main*, s32, s32, s32);

extern "C" void fn_27_7313C(Main* self) {
    pop__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacebll((Main*)((char*)self + 4), self->v4(), self->v13(), self->v28());
    self->v29(self->v3() - 1);
}
