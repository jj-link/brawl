#pragma force_active on
#include <types.h>
#include <it/it_manager.h>
#include <so/so_module_accesser.h>

extern "C" {
int fn_27_2C0E10(void* mgr, u32 id);
int fn_27_2C0FBC(void* mgr, u32 id, int flag);
extern const float lbl_27_rodata_46C8[];
}

class FigSub {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual int s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual int s13();
};

struct FigMgr {
    u32 unk0;
    void* unk4;
    FigSub sub;
    char pad[0x304];
    int unk310;
};

struct ModelBase {
    char pad[8];
};

class ModelMod : public ModelBase {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void setNodeScale(u32, Vec3f*);
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void setNodeTranslate(u32, Vec3f*);
};

struct CtxBase {
    char pad[0x3c];
};

class Ctx : public CtxBase {
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
    char pad2[0x20];
    soModuleAccesser* accesser;
    char pad3[0x8c4 - 0x64];
    u32 id;
};

extern "C" int fn_27_29A624(void* unused, Ctx* arg) {
    int flag;
    const float* k = lbl_27_rodata_46C8;
    soWorkManageModule* work = *(soWorkManageModule**)(*(char**)((char*)arg->accesser + 0xd8) + 0x64);
    FigMgr* fig = (FigMgr*)itManager::getInstance()->m_figureManager;
    if (!work->isFlag(0x12000003)) {
        flag = 0;
        int total = fig->sub.s13();
        if (fig->sub.s3() >= total || fig->sub.s3() >= fig->unk310) {
            flag = 1;
        }
        if (flag == 0) {
            u32 id = arg->id;
            if (fn_27_2C0FBC(fig, fn_27_2C0E10(itManager::getInstance()->m_figureManager, id) ? id : 1, 1) != 0) {
                work->onFlag(0x12000003);
            }
        }
    }
    if (work->getFloat(0x11000002) > k[5]) {
        float ay = work->getFloat(0x11000001);
        Vec3f a;
        a.m_x = work->getFloat(0x11000000);
        a.m_y = ay;
        a.m_z = k[24];
        float by = work->getFloat(0x11000003);
        Vec3f b;
        b.m_x = work->getFloat(0x11000002);
        b.m_y = by;
        b.m_z = k[0];
        ModelMod* model = (ModelMod*)&arg->accesser->getModelModule();
        model->setNodeTranslate(2, &a);
        model->setNodeScale(2, &b);
        arg->v43();
    }
    return 1;
}
