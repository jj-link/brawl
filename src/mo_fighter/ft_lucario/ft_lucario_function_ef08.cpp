#include <types.h>
#pragma force_active on

struct Pad8 {
    s32 _0;
    s32 _4;
};

class Ent : public Pad8 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual s32 f55(s32, s32);
};

class Obj70 {
public:
    virtual void g0();
    virtual void g1();
    virtual void g2();
    virtual void g3(s32, void*);
};

struct Mid {
    char pad[0x10];
    Ent* ent;
    char pad2[0x70 - 0x14];
    Obj70* obj70;
};

struct Outer {
    char pad[0xd8];
    Mid* mid;
};

extern "C" {
s32 fn_118_F6EC(f32 value, void* self);
extern const float lbl_118_rodata_38;
extern const float lbl_118_rodata_3C;

void fn_118_EF08(void*, Outer* arg) {
    Ent* ent = arg->mid->ent;
    if ((ent->f55(2, 0) != 0 &&
         fn_118_F6EC(lbl_118_rodata_3C, arg) != 0) ||
        (ent->f55(4, 0) != 0 &&
         fn_118_F6EC(lbl_118_rodata_38, arg) != 0)) {
        arg->mid->obj70->g3(0x68, arg);
    }
}
}
