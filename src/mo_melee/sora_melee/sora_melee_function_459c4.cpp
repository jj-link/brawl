#include <so/so_value_accesser.h>
#include <so/model/so_model_module_simple.h>

#pragma force_active on

struct ArgData {
    int type;
    unsigned long data;
};

struct Arg {
    const ArgData* p;
    unsigned char null;

    Arg() : p(0), null(0) {}
    Arg(const ArgData* q) : p(q), null(0) {}

    int type() const {
        return null == 1 ? -1 : p->type;
    }

    unsigned long value() const {
        return null == 1 ? 0 : p->data;
    }

    bool boolean() const {
        return null == 1 ? false : p->data != 0;
    }
};

struct List {
    virtual void v0();
    virtual void v1();
    virtual const ArgData* at(int) const;
    virtual int size() const;
    virtual void v4();
    virtual void v5();
    virtual void shift();
    void advance() { shift(); }

    char data[12];

    Arg get(int i) const {
        Arg a(at(i));
        return a;
    }
};

struct Cmd {
    virtual void v0();
    virtual signed char group();
    virtual signed char type();
    virtual int count();
    virtual void v4();
    virtual List args();
    virtual bool getArg(Arg*, int);
};

class Class_1250 {
public:
    virtual void fn_27_13C90();
    virtual void fn_27_14068();
    virtual void fn_27_140C0();
    virtual void fn_27_1412C();
    virtual void fn_27_14134();
    virtual void fn_27_14370();
    virtual void fn_27_14A28();
    virtual void fn_27_14A30();
    virtual void fn_27_14A38();
    virtual void fn_27_14A48();
    virtual void fn_27_14A68();
    virtual void fn_27_14AD8(int);
    virtual void fn_27_14A60();
    virtual void fn_27_14D08();
    virtual void fn_27_14EDC();
    virtual void fn_27_14D00(int, int, int);
    virtual void fn_27_14B80(const char*, int, int);
    virtual void fn_27_14B88(const char*, int, int);
    virtual void fn_27_16A70(int, int);
    virtual void fn_27_16AB8(int, int);
    virtual void fn_27_1CBB4();
    virtual void fn_27_14A20(bool, int);
    virtual void fn_27_1CBAC();
    virtual void fn_27_1CBA4();
    virtual void fn_27_14B98();
    virtual void fn_27_14B90();
    virtual void fn_27_1CB88();
    virtual void fn_27_14CF8();
    virtual void fn_27_16778();
    virtual void fn_27_1688C();
    virtual void fn_27_1C2E4();
    virtual void fn_27_1BC08();
    virtual void fn_27_1BCF0();
    virtual void fn_27_16AE0();
    virtual void fn_27_15604();
    virtual void fn_27_16CA8();
    virtual void fn_27_16CB0();
    virtual void fn_27_1CB80();
    virtual void fn_27_16CB8(bool);
    virtual void fn_27_16CC0();
    virtual void fn_27_16E88(int, int);
    virtual void fn_27_16FB4(int);
    virtual void fn_27_170A8();
    virtual void fn_27_171D0();
    virtual void fn_27_1CB6C();
    virtual void fn_27_1CB38();
    virtual void fn_27_17334();
    virtual void fn_27_17374();
    virtual void fn_27_173A8();
    virtual void fn_27_17444();
    virtual void fn_27_17518();
    virtual void fn_27_1754C();
    virtual void fn_27_17584();
    virtual void fn_27_175FC();
    virtual void fn_27_17674();
    virtual void fn_27_17A9C();
    virtual void fn_27_17688();
    virtual void fn_27_17970();
    virtual void fn_27_17AD0();
    virtual void fn_27_17B18();
    virtual void fn_27_17B94();
    virtual void fn_27_17C10();
    virtual void fn_27_17C90();
    virtual void fn_27_17D0C();
    virtual void fn_27_17D88();
    virtual bool fn_27_17E00(signed char);
};

extern "C" bool fn_27_459C4(
    Class_1250* self, Cmd* cmd, soModuleAccesser* acc
) {
    if (!self->fn_27_17E00(cmd->group()))
        return false;

    if (cmd->type() <= -1 || cmd->type() >= 48)
        return false;

    switch (cmd->type()) {
    case 5: {
        Arg a;
        if (!cmd->getArg(&a, 0) || a.type() != 0)
            return true;
        self->fn_27_16AB8(a.value(), 0);
        return true;
    }

    case 6: {
        Arg a;
        if (!cmd->getArg(&a, 0) || a.type() != 0)
            return true;
        self->fn_27_16A70(a.value(), 0);
        return true;
    }

    case 7:
    case 8:
    case 39: {
        List args = cmd->args();
        const Arg& a = args.get(0);
        if (a.type() != 0)
            return true;

        args.advance();
        const Arg& b = args.get(0);
        if (b.type() != 0)
            return true;

        if (cmd->type() == 7) {
            unsigned long first = a.value();
            self->fn_27_14D00(first, b.value(), 0);
        } else if (cmd->type() == 8) {
            const char* node =
                reinterpret_cast<const char*>(acc->getModelModule().getCorrectNodeId(a.value()));
            self->fn_27_14B80(node, b.value(), 0);
        } else {
            const char* node =
                reinterpret_cast<const char*>(acc->getModelModule().getCorrectNodeId(a.value()));
            self->fn_27_14B88(node, b.value(), 0);
        }
        return true;
    }

    case 33: {
        const List args = cmd->args();
        bool flag = args.get(0).boolean();
        int value = 0;

        if (cmd->count() == 2) {
            if (args.get(1).type() == 0)
                value = args.get(1).value();
            else if (args.get(1).type() == 5)
                value = soValueAccesser::getValueInt(
                    acc, args.get(1).value(), 0
                );
            else
                return true;
        }

        self->fn_27_14A20(flag, value);
        return true;
    }

    case 37: {
        const List args = cmd->args();
        self->fn_27_16CB8(args.get(0).boolean());
        return true;
    }

    case 40:
        self->fn_27_14AD8(0);
        return true;

    case 41: {
        const List args = cmd->args();
        int first = args.get(0).value();
        int value = 0;

        if (cmd->count() == 2) {
            if (args.get(1).type() == 0)
                value = args.get(1).value();
            else if (args.get(1).type() == 5)
                value = soValueAccesser::getValueInt(
                    acc, args.get(1).value(), 0
                );
            else
                return true;
        }

        self->fn_27_16E88(first, value);
        return true;
    }

    case 42: {
        const List args = cmd->args();
        int value = 0;

        if (cmd->count() == 1) {
            if (args.get(0).type() == 0)
                value = args.get(0).value();
            else if (args.get(0).type() == 5)
                value = soValueAccesser::getValueInt(
                    acc, args.get(0).value(), 0
                );
            else
                return true;
        }

        self->fn_27_16FB4(value);
        return true;
    }
    }

    return false;
}
