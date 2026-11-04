#include <so/work/so_work_manage_module_impl.h>
#pragma force_active on

extern "C" {
void fn_27_12BAF8(void* object, int param);
extern const float lbl_101_rodata_8;
}

class NessRecoveryModule {
public:
    char m_baseNonPoly[8];
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
    virtual void v32() = 0;
    virtual void v33() = 0;
    virtual void v34() = 0;
    virtual void v35() = 0;
    virtual void v36() = 0;
};

extern "C" void fn_101_B924(void* object, int param) {
    fn_27_12BAF8(object, param);
    unsigned char* storage = static_cast<unsigned char*>(object);
    soWorkManageModule* work = *reinterpret_cast<soWorkManageModule**>(
        *reinterpret_cast<unsigned char**>(
            *reinterpret_cast<unsigned char**>(storage + 0x60) + 0xd8) + 0x64);
    work->offFlag(0x1200003d);
    work->setFloat(lbl_101_rodata_8, 0x11000015);
    work->setFloat(lbl_101_rodata_8, 0x11000016);
    work->setInt(0, 0x10000040);
    NessRecoveryModule* mod = *reinterpret_cast<NessRecoveryModule**>(
        *reinterpret_cast<unsigned char**>(
            *reinterpret_cast<unsigned char**>(storage + 0x60) + 0xd8) + 0x9c);
    mod->v35();
}