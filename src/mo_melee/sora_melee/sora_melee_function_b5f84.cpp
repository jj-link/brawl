#include <so/so_value_accesser.h>
#pragma force_active on

struct ArgData {
    int type;
    unsigned long data;
};
struct Arg {
    const ArgData* p;
    unsigned char null;
    Arg() : p(0), null(0) {}
    int type() const { return null == 1 ? -1 : p->type; }
    unsigned long value() const { return null == 1 ? 0 : p->data; }
};

class Class_1250 {
public:
    virtual void fn_27_13C90();
    virtual signed char fn_27_14068();
    virtual signed char fn_27_140C0();
    virtual void fn_27_1412C();
    virtual void fn_27_14134();
    virtual void fn_27_14370();
    virtual int fn_27_14A28(Arg*, int);
    virtual void fn_27_14A30();
    virtual void fn_27_14A38();
    virtual void fn_27_14A48();
    virtual void fn_27_14A68();
    virtual void fn_27_14AD8();
    virtual void fn_27_14A60();
    virtual void fn_27_14D08();
    virtual void fn_27_14EDC();
    virtual void fn_27_14D00();
    virtual void fn_27_14B80();
    virtual void fn_27_14B88();
    virtual void fn_27_16A70();
    virtual void fn_27_16AB8();
    virtual void fn_27_1CBB4();
    virtual void fn_27_14A20();
    virtual void fn_27_1CBAC();
    virtual void fn_27_1CBA4();
    virtual void fn_27_14B98();
    virtual void fn_27_14B90();
    virtual void fn_27_1CB88();
};
class Class_16D80 {
public:
    virtual void fn_27_B21D0();
    virtual void fn_27_B4674();
    virtual void fn_27_B2228();
    virtual void fn_27_B2248(int, bool);
    virtual void fn_27_B2304();
    virtual void fn_27_B2348();
    virtual void fn_27_B238C(int);
    virtual void fn_27_B242C(int);
    virtual void fn_27_B24B0();
    virtual void fn_27_B2530();
    virtual void fn_27_B2668();
    virtual void fn_27_B48D0();
    virtual void fn_27_B2728();
    virtual void fn_27_B2888();
    virtual void fn_27_B294C();
    virtual void fn_27_B2A10();
    virtual void fn_27_B2A24();
    virtual void fn_27_B2A58();
    virtual void fn_27_B2AA0();
    virtual void fn_27_B2AE8();
    virtual void fn_27_B2B2C();
    virtual void fn_27_B2B64();
    virtual void fn_27_B2BD0();
    virtual void fn_27_B2B60();
    virtual void fn_27_B4664();
    virtual void fn_27_B48F4();
    virtual int fn_27_B496C(signed char);
};

extern "C" int fn_27_B5F84(Class_16D80* self, Class_1250* cmd, soModuleAccesser* acc) {
    if (!self->fn_27_B496C(cmd->fn_27_14068())) return 0;
    if (cmd->fn_27_140C0() <= -1 || cmd->fn_27_140C0() >= 3) return 0;
    switch (cmd->fn_27_140C0()) {
    case 0:
    case 2: {
        Arg arg;
        if (!cmd->fn_27_14A28(&arg, 0)) return 1;
        int value;
        if (arg.type() == 0) value = arg.value();
        else if (arg.type() == 5) value = soValueAccesser::getValueInt(acc, arg.value(), 0);
        else return 1;
        if (cmd->fn_27_140C0() == 2) self->fn_27_B238C(value);
        else self->fn_27_B2248(value, true);
        return 1;
    }
    case 1: {
        Arg arg;
        if (!cmd->fn_27_14A28(&arg, 0)) return 1;
        int value;
        if (arg.type() == 0) value = arg.value();
        else if (arg.type() == 5) value = soValueAccesser::getValueInt(acc, arg.value(), 0);
        else return 1;
        self->fn_27_B242C(value);
        return 1;
    }
    }
    return 0;
}
