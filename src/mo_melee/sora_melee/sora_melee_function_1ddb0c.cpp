#include <types.h>
#pragma force_active on

struct Msg {
    s32 id;
    u8 flag;
};

struct Pad8 {
    s32 a;
    s32 b;
};

struct Obj8 : public Pad8 {
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual void v28() = 0;
    virtual void v29() = 0;
    virtual void v30() = 0;
    virtual void v31() = 0;
    virtual s32 v32() = 0;
    virtual void v33() = 0;
    virtual void v34() = 0;
    virtual void v35() = 0;
    virtual void v36() = 0;
    virtual void v37() = 0;
    virtual void v38() = 0;
    virtual void v39() = 0;
    virtual void v40() = 0;
    virtual void v41() = 0;
    virtual void v42() = 0;
    virtual void v43(s32 x) = 0;
};

struct IfaceOnly {
    virtual void w0() = 0;
    virtual void w1() = 0;
    virtual void w2() = 0;
    virtual void w3() = 0;
    virtual void w4() = 0;
    virtual void w5() = 0;
    virtual void w6() = 0;
    virtual void w7() = 0;
    virtual void w8() = 0;
    virtual void w9() = 0;
    virtual void w10() = 0;
    virtual void w11() = 0;
    virtual void w12() = 0;
    virtual void w13() = 0;
    virtual void w14() = 0;
    virtual void w15(s32 x, void* p) = 0;
};

extern "C" void fn_27_1DDB0C(void* unused, u8* obj) {
    Obj8* ob = *(Obj8**)(*(u8**)(obj + 0xd8) + 0x9c);
    ob->v43(1);

    Obj8* ob2 = *(Obj8**)(*(u8**)(obj + 0xd8) + 0x9c);
    s32 r = ob2->v32();

    if (r <= 0) {
        Msg msg;
        msg.id = 0x839;
        msg.flag = 0;
        IfaceOnly* ob3 = *(IfaceOnly**)(*(u8**)(obj + 0xd8) + 0x54);
        ob3->w15(1, &msg);
    }
}
