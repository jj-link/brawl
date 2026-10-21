#include <types.h>
#pragma force_active on

class soA {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* v4(s32 a);
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual float v12(s32 a);
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
    virtual void v48(float f);
};

struct soR {
    char pad[0x14];
    float f;
};

struct soHolder {
    char pad0[0x1c];
    soA* m_c;
    char pad1[0x64 - 0x20];
    soA* m_64;
};

struct soOwner {
    char pad[0xd8];
    soHolder* m_holder;
};

extern "C" void fn_27_3A0D7C(void*);
extern "C" void fn_27_3A0FD8(void*);
extern "C" soR* fn_27_14954C(void*, void*);
extern char g_ftCommonDataAccesser[];

extern "C" void fn_27_3A0920(s32 unused, soOwner* arg1) {
    fn_27_3A0D7C(arg1);
    soR* r = fn_27_14954C(g_ftCommonDataAccesser, arg1->m_holder->m_64->v4(0x10000009));
    float f = arg1->m_holder->m_64->v12(0x11000009);
    f = f * r->f;
    arg1->m_holder->m_c->v48(f);
    fn_27_3A0FD8(arg1);
}
