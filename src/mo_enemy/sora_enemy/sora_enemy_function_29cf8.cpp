#pragma force_active on
struct acCmdArgConv;
class soModuleAccesser;

class soValueAccesser {
public:
    static int getValueInt(soModuleAccesser*, unsigned long, unsigned long);
};

template <class T>
class ArrayBase {
public:
    virtual void v0();
    virtual T& at(int);
    virtual const T& at(int) const;
    virtual void v3();
    virtual void v4();
    virtual ~ArrayBase();
};

template <class T>
class soArrayContractibleTable : public ArrayBase<T> {
public:
    virtual ~soArrayContractibleTable();
    char data[12];
};

class Cmd {
public:
    virtual void v0();
    virtual signed char getGroup();
    virtual signed char getType();
    virtual int getArgNum();
    virtual void v4();
    virtual soArrayContractibleTable<const acCmdArgConv> getArgList();
};

class soAnimCmdEventObserver {
public:
    virtual void addObserver();
    virtual void fn_41_29CDC();
    virtual void fn_41_29CF8();
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int, int);
};

struct Arg {
    const acCmdArgConv* p;
    unsigned char null;

    Arg(const acCmdArgConv* q) : p(q), null(0) {}
};

#pragma inline_depth(8)
#pragma inline_max_size(1000)
inline Arg getArg(const ArrayBase<const acCmdArgConv>& list, int index) {
    Arg arg(&list.at(index));
    return arg;
}

struct Owner {
    char pad[0x5c];
    int a;
    int b;
};

extern "C" int fn_41_A184(Arg);
extern "C" int fn_41_A1C4(Arg);
extern "C" unsigned long fn_41_A1E4(Arg);
extern "C" void fn_41_28F74(void*, unsigned int, int);
extern "C" void fn_41_28EF0(void*, int);
extern "C" int fn_41_29BBC(void*, int, int);

extern "C" bool fn_41_29CF8(Owner* self, Cmd* cmd, soModuleAccesser* module) {
    if (cmd->getGroup() != 0x6a)
        return false;

    signed char type = cmd->getType();
    int count = cmd->getArgNum();

    if (type <= -1 || type >= 5)
        return false;

    switch (type) {
    case 0:
    case 1: {
        if (count < 1 || count > 5)
            return true;

        const soArrayContractibleTable<const acCmdArgConv> list = cmd->getArgList();

        int mode;
        if (type == 0)
            mode = 1;
        else if (type == 1)
            mode = 0;
        else
            return true;

        for (int i = 0; i < count; i++) {
            fn_41_28F74(self, mode, fn_41_A184(getArg(list, i)));
        }
        return true;
    }

    case 2: {
        if (count < 0 || count > 4)
            return true;

        const soArrayContractibleTable<const acCmdArgConv> list = cmd->getArgList();

        if (count == 0) {
            fn_41_28EF0(self, -1);
        } else {
            for (int i = 0; i < count; i++) {
                fn_41_28EF0(self, fn_41_A184(getArg(list, i)));
            }
        }
        return true;
    }

    case 3:
        if (count < 0 || count > 0)
            return true;
        self->a = -2;
        self->b = -1;
        return true;

    case 4: {
        if (count < 3 || count > 3)
            return true;

        const soArrayContractibleTable<const acCmdArgConv> list = cmd->getArgList();
        int x;
        int y;

        if (fn_41_A1C4(getArg(list, 0)) == 5) {
            x = soValueAccesser::getValueInt(module, fn_41_A1E4(getArg(list, 0)), 0);
        } else {
            x = fn_41_A184(getArg(list, 0));
        }

        if (fn_41_A1C4(getArg(list, 1)) == 5) {
            y = soValueAccesser::getValueInt(module, fn_41_A1E4(getArg(list, 1)), 0);
        } else {
            y = fn_41_A184(getArg(list, 1));
        }

        if (fn_41_A1C4(getArg(list, 2)) != 5)
            return true;

        int index = fn_41_A1E4(getArg(list, 2));
        int value = fn_41_29BBC(self, x, y);
        ((Object_vptr_0*)*(void**)(*(char**)((char*)module + 0xd8) + 0x64))
            ->slot5(value, index);
        return true;
    }
    }

    return false;
}
