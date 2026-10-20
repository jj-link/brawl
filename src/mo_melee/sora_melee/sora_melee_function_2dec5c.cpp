#include <types.h>
#pragma force_active on

extern u32 g_ftCommonDataAccesser;
extern "C" u32 fn_27_147D94(u32 unused, s32 id);

class FtPad3c {
public:
    u8 pad[0x3c];
};

class FtPolyA : public FtPad3c {
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
    virtual u32 getId();
};

class FtPolyB {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void setValue(f32 value);
};

extern "C" void fn_27_2DEC5C(void* unused, u8* p) {
    FtPolyA* a = *(FtPolyA**)(p + 8);
    s32 id = a->getId();
    f32* f = (f32*)fn_27_147D94((u32)&g_ftCommonDataAccesser, id);
    u8* c = *(u8**)(p + 0xd8);
    FtPolyB* b = *(FtPolyB**)(c + 8);
    b->setValue(f[1]);
}
