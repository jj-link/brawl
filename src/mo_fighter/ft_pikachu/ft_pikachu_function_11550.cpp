#include <so/so_module_accesser.h>
#pragma force_active on

class VisibilityLike {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void f7(int);
};

class EffectLike {
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
    virtual void f21(int);
};

class WorkLike {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void setInt(int, unsigned long);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void setFloat(float, unsigned long);
};

extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(soModuleAccesser* accesser, unsigned long id, unsigned long index);
extern const float lbl_98_rodata_88;
extern const float lbl_98_rodata_8C;

extern "C" void fn_98_11550(void*, soModuleAccesser* accesser) {
    WorkLike* work = (WorkLike*)accesser->m_enumerationStart->m_workManageModule;
    ((VisibilityLike*)accesser->m_enumerationStart->m_visibilityModule)->f7(0);
    ((EffectLike*)accesser->m_enumerationStart->m_effectModule)->f21(8);
    int value = (int)(lbl_98_rodata_88 * getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xFCA, 0));
    work->setInt(value, 0x20000001);
    work->setFloat(lbl_98_rodata_8C, 0x21000004);
}
