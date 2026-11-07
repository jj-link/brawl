#include <ac/ac_cmd_interpreter.h>
#include <so/so_value_accesser.h>
#include <mt/mt_prng.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6(acCmdArg*, int);
};

extern "C" void fn_27_70D88(acCmdInterpreter* self) {
    if (*(soModuleAccesser**)((char*)self + 0x44) && *(void**)((char*)self + 0xc)) {
        Object_vptr_0* cmd = (Object_vptr_0*)self->getCurrentCmd();
        float upper;
        float lower = 0.0f;
        acCmdArg arg;
        cmd->slot6(&arg, 0);
        if (arg.getArgType() == 1)
            upper = arg.getFloatData();
        else
            upper = soValueAccesser::getValueFloat(*(soModuleAccesser**)((char*)self + 0x44), arg.getIntData(), 0);
        if (cmd->slot3() >= 2) {
            lower = upper;
            cmd->slot6(&arg, 1);
            if (arg.getArgType() == 1)
                upper = arg.getFloatData();
            else
                upper = soValueAccesser::getValueFloat(*(soModuleAccesser**)((char*)self + 0x44), arg.getIntData(), 0);
        }
        float diff = upper - lower;
        if (diff > 0.0f)
            lower += diff * randf();
        self->systemCmdFuncWaitSub(lower);
    }
}
