#pragma force_active on
typedef int s32;

class soA {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* v4(s32 a);
    virtual void v5(s32 a, s32 b);
    virtual void v6();
    virtual void v7(s32 a);
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

struct Holder {
    char pad0[0x1c];
    soA* m_c;
    char pad1[0x64 - 0x20];
    soA* m_64;
};

struct Owner {
    char pad0[8];
    void* m8;
    char pad1[0xd8 - 0xc];
    Holder* holder;
};

extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" void* fn_27_14954C(void*, void*);
extern "C" s32 fn_27_39FA04(void*);
extern "C" void fn_27_39FAD4(void*);
extern char g_ftCommonDataAccesser[];
extern char lbl_27_data_9B6C0[];
extern char lbl_27_data_248[];

extern "C" void fn_27_3A07AC(s32 unused, Owner* arg1) {
    soA* m64 = arg1->holder->m_64;
    s32* r29 = (s32*)fn_27_14954C(g_ftCommonDataAccesser, m64->v4(0x10000009));
    if (fn_27_39FA04(__dynamic_cast(arg1->m8, 0x3c, lbl_27_data_9B6C0, lbl_27_data_248, 1)) < *r29) {
        m64->v7(0x10000005);
        void* d = __dynamic_cast(arg1->m8, 0x3c, lbl_27_data_9B6C0, lbl_27_data_248, 1);
        soA* m = arg1->holder->m_64;
        m->v5(fn_27_39FA04(d), 0x10000006);
        fn_27_39FAD4(arg1);
    }
    float* r31 = (float*)fn_27_14954C(g_ftCommonDataAccesser, arg1->holder->m_64->v4(0x10000009));
    float f = arg1->holder->m_64->v12(0x11000009);
    f = f * *(float*)((char*)r31 + 0x14);
    arg1->holder->m_c->v48(f);
}
