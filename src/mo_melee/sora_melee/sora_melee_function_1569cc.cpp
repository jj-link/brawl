#pragma force_active on
typedef unsigned long u32;
typedef int s32;

class soModuleAccesser;

class soValueAccesser {
public:
    static s32 getConstantInt(soModuleAccesser* mod, u32 id, u32 type);
};

class soVirtualTarget {
public:
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
    virtual u32 v19(u32 arg);
};

struct soInner {
    unsigned char pad[0x64];
    soVirtualTarget* m_target;
};

class soModuleAccesser {
public:
    unsigned char pad[0xd8];
    soInner* m_inner;
};

extern "C" extern const s32 lbl_27_rodata_1F30[3][2];

extern "C" int fn_27_1569CC(int unused, int dflt, soModuleAccesser* mod) {
    if (mod->m_inner->m_target->v19(0x12000012) == 1) {
        s32 idx = soValueAccesser::getConstantInt(mod, 0x59e8, 0);
        if (idx != -1) {
            return lbl_27_rodata_1F30[idx][0];
        }
    }
    return dflt;
}
