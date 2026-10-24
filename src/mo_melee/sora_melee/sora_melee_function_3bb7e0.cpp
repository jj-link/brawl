#pragma force_active on

class Base {
public:
    char pad[0x3C];
};

class SomeClass : public Base {
public:
    virtual int v0() = 0;
    virtual int v1() = 0;
    virtual int v2() = 0;
    virtual int v3() = 0;
    virtual int v4() = 0;
    virtual int v5() = 0;
    virtual int v6() = 0;
    virtual int v7() = 0;
    virtual int v8() = 0;
    virtual int v9() = 0;
    virtual int v10() = 0;
    virtual int v11() = 0;
    virtual int v12() = 0;
    virtual int v13() = 0;
    virtual int v14() = 0;
    virtual int v15() = 0;
    virtual int v16() = 0;
    virtual int v17() = 0;
    virtual int v18() = 0;
    virtual int v19() = 0;
    virtual int v20() = 0;
    virtual int v21() = 0;
    virtual int v22() = 0;
    virtual int v23() = 0;
    virtual int v24() = 0;
    virtual int v25() = 0;
    virtual int v26() = 0;
    virtual int v27() = 0;
    virtual int v28() = 0;
    virtual int v29() = 0;
    virtual int v30() = 0;
    virtual int v31() = 0;
    virtual int v32() = 0;
    virtual int v33() = 0;
    virtual int v34() = 0;
    virtual int v35() = 0;
    virtual int v36() = 0;
    virtual int v37() = 0;
    virtual int v38() = 0;
    virtual int v39() = 0;
    virtual int v40() = 0;
};

class TargetClass {
public:
    virtual void v0(int) = 0;
    virtual void v1(int) = 0;
    virtual void v2(int) = 0;
    virtual void v3(int) = 0;
    virtual void v4(int) = 0;
    virtual void v5(int) = 0;
    virtual void v6(int) = 0;
    virtual void v7(int) = 0;
    virtual void v8(int) = 0;
    virtual void v9(int) = 0;
    virtual void v10(int) = 0;
    virtual void v11(int) = 0;
    virtual void v12(int) = 0;
    virtual void v13(int) = 0;
    virtual void v14(int) = 0;
    virtual void v15(int) = 0;
    virtual void v16(int) = 0;
    virtual void v17(int) = 0;
    virtual void v18(int) = 0;
    virtual void v19(int) = 0;
    virtual void v20(int) = 0;
    virtual void v21(int) = 0;
    virtual void v22(int) = 0;
    virtual void v23(int) = 0;
    virtual void v24(int) = 0;
    virtual void v25(int) = 0;
    virtual void v26(int) = 0;
    virtual void v27(int) = 0;
    virtual void v28(int) = 0;
    virtual void v29(int) = 0;
    virtual void v30(int) = 0;
    virtual void v31(int) = 0;
    virtual void v32(int) = 0;
    virtual void v33(int) = 0;
    virtual void v34(int) = 0;
    virtual void v35(int) = 0;
    virtual void v36(int) = 0;
    virtual void v37(int) = 0;
    virtual void v38(int) = 0;
    virtual void v39(int) = 0;
    virtual void v40(int) = 0;
    virtual void v41(int) = 0;
    virtual void v42(int) = 0;
    virtual void v43(int) = 0;
    virtual void v44(int) = 0;
    virtual void v45(int) = 0;
};

struct Mid {
    char pad[0x88];
    TargetClass* target;
};

struct Self {
    char pad0[8];
    SomeClass* obj;
    char pad1[0xCC];
    Mid* mid;
};

extern "C" void fn_27_3BB7E0(int a1, int a2, int a3, int a4, Self* self) {
    if (self->obj->v40() == 5) {
        switch (a3) {
        case 0x139:
        case 0x13A:
        case 0x13B:
            self->mid->target->v45(1);
            break;
        }

        switch (a2) {
        case 0x139:
        case 0x13A:
        case 0x13B:
            self->mid->target->v45(0);
            break;
        }
    }
}
