#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

class Motion {
public:
    u8 pad[0x3c];

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
    virtual u32 getKind();
};

class VBase {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual VBase* s8(u32);
};

class VBase2 {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s8();
};

extern "C" u32* fn_27_14554C(void*, u32, u32);
extern "C" u32 g_ftCommonDataAccesser[];

extern "C" void fn_27_16035C(void* a, u32 kind, void* c, u8* obj)
{
    Motion* p = *(Motion**)(obj + 8);
    u32 motion = p->getKind();
    u32* r = fn_27_14554C(&g_ftCommonDataAccesser, motion, kind);

    if (((r[1] >> 22) & 1) == 1) {
        VBase* b = *(VBase**)(*(u8**)(obj + 0xd8) + 0x7c);
        VBase* b2 = b->s8(0);
        ((VBase2*)b2)->s8();
    }
}
