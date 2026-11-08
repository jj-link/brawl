#include <so/so_module_accesser.h>
#pragma force_active on

struct Speed {
    float x, y;
};

class KineticView : public soNullable {
public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual Speed getSumSpeed(const short&);
};

struct Prefix {
    char pad[8];
};

class Physics : public Prefix {
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
    virtual int v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49(int, Vec3f*);
};

extern "C" KineticView* fn_27_8CE14(void*);
extern "C" Vec3f fn_104_24B00(const Vec3f&, const Vec3f&);
extern float lbl_104_rodata_1B8;

extern "C" void fn_104_2493C(void*, soModuleAccesser* a) {
    soLinkModule* link = a->m_enumerationStart->m_linkModule;
    Physics* physics = static_cast<Physics*>(a->m_enumerationStart->m_physicsModule);

    Vec3f p1 = link->getParentModelNodeGlobalPosition(3, (u32)30, true);
    Vec3f p0 = link->getParentModelNodeGlobalPosition(3, (u32)30, false);
    short flag = -1;
    Speed speed = fn_27_8CE14(link->getParent(3))->getSumSpeed(flag);

    Vec3f v;
    v.m_x = speed.x;
    v.m_y = speed.y;
    v.m_z = lbl_104_rodata_1B8;

    Vec3f result = fn_104_24B00(fn_104_24B00(p0, p1), v);
    physics->v49(0, &result);

    if (static_cast<Physics*>(a->m_enumerationStart->m_physicsModule)->v42() == 1) {
        if (!a->getWorkManageModule().isFlag(0x12000004)) {
            a->getSoundModule().playSENo3d((SndID)0x1037, false);
            a->getWorkManageModule().onFlag(0x12000004);
        }
    } else {
        a->getWorkManageModule().offFlag(0x12000004);
    }
}
