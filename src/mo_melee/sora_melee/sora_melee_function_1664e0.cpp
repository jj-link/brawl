#pragma force_active on
typedef unsigned int u32;

extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void* mod, u32 a, u32 b);

class Vt {
public:
    virtual void v0(u32 a);
    virtual void v1(u32 a);
    virtual void v2(u32 a);
    virtual void v3(u32 a);
    virtual void v4(u32 a);
    virtual void v5(u32 a);
    virtual void v6(u32 a);
    virtual void v7(u32 a);
    virtual void v8(u32 a);
    virtual void v9(u32 a);
    virtual void v10(u32 a);
    virtual void v11(u32 a);
    virtual void v12(u32 a);
    virtual void v13(u32 a);
    virtual void v14(u32 a);
    virtual void v15(u32 a);
    virtual void v16(u32 a);
    virtual void v17(u32 a);
    virtual void v18(u32 a);
    virtual void v19(u32 a);
    virtual void v20(u32 a);
    virtual void v21(u32 a);
    virtual void v22(u32 a);
    virtual void v23(u32 a);
    virtual void v24(u32 a);
    virtual void v25(u32 a);
    virtual void v26(u32 a);
    virtual void v27(u32 a);
    virtual void v28(u32 a);
    virtual void v29(u32 a);
    virtual void v30(u32 a);
    virtual void v31(u32 a);
    virtual void v32(u32 a);
    virtual void v33(u32 a);
    virtual void v34(u32 a);
    virtual void v35(u32 a);
    virtual void v36(u32 a);
    virtual void v37(u32 a);
    virtual void v38(u32 a);
    virtual void v39(u32 a);
    virtual void v40(u32 a);
    virtual void v41(u32 a);
    virtual void v42(u32 a);
};

struct X {
    char pad[0x60];
    Vt* p60;
    Vt* p64;
};

struct M {
    char pad[0xd8];
    X* px;
};

extern "C" {
void fn_27_1664E0(void* self, M* mod) {
    getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(mod, 0xbc1, 0);
    mod->px->p64->v13(0x21000006);
    mod->px->p64->v18(0x22000012);
    mod->px->p60->v40(0);
}
}
