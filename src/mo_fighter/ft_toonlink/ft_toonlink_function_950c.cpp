#include <types.h>
#include <so/so_module_accesser.h>
#include <so/model/so_model_module_simple.h>
#include <so/work/so_work_manage_module_impl.h>
#pragma force_active on

struct ValueModule {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual Vec3f getValue(int, int);
};

extern "C" void fn_121_950C(char* self) {
    soModuleAccesser* accesser = *(soModuleAccesser**)(self + 0x60);
    soWorkManageModule& work = accesser->getWorkManageModule();
    soModelModule& model = accesser->getModelModule();
    ValueModule* value = (ValueModule*)&accesser->getMotionModule();
    Vec3f pos;
    pos = value->getValue(0x1e3, model.getCorrectNodeId(0x12c));
    work.setFloat(pos.m_x, 0x11000013);
    work.setFloat(pos.m_y, 0x11000014);
    (*(soWorkManageModule**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x64))->offFlag(0x1200003d);
}
