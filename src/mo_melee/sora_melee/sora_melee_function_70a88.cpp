#include <ac/ac_cmd_interpreter.h>
#pragma force_active on

class Class_C80 {
public:
    virtual bool fn_27_FEE4() const;
    virtual signed char fn_27_FF68() const;
    virtual signed char fn_27_FFAC() const;
};

extern "C" int fn_27_70A88(acCmdInterpreter* self) {
    if (self->acCmdInterpreter::isSkipEnd() == true)
        return 1;
    const Class_C80* cmd = reinterpret_cast<const Class_C80*>(self->getCurrentCmd());
    if (cmd->fn_27_FEE4() == true)
        return 1;
    int mode = (int)((*(unsigned int*)((char*)self + 0x30) << 2) & 0xF0000000) >> 29;
    if (mode == 1) {
        if ((cmd->fn_27_FF68() == 4 && cmd->fn_27_FFAC() == 0) ||
            (cmd->fn_27_FF68() == 1 && cmd->fn_27_FFAC() == 1))
            return 1;
    } else if (mode == 2) {
        acCmdInterpreterStackData* data = self->getLastSystemStackData();
        if (data) {
            if (data->kind == 9)
                return 1;
            if (data->kind == 8)
                return 1;
        }
    }
    return 0;
}
