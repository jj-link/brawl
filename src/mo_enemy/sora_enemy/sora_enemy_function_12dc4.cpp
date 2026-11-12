#pragma force_active on
class soModuleAccesser;
struct Modules;
class WorkModule;
class Self;

extern const float lbl_41_rodata_BE0;

class soValueAccesser {
public:
    static int getValueInt(soModuleAccesser*, unsigned long, unsigned long);
    static float getValueFloat(soModuleAccesser*, unsigned long, unsigned long);
};

struct acCmdArgConv {
    int argType;
    int data;
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

class WorkModule {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int, unsigned long);
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual int slot17(unsigned long);
};

struct Modules {
    char pad0[0xc];
    void* posture;
    char pad10[0x54];
    WorkModule* work;
    char pad68[0x14];
    void* link;
};

class soModuleAccesser {
public:
    char pad0[8];
    void* object;
    char pad10[0xcc];
    Modules* modules;
};

struct Pad8 {
    int a;
    int b;
};

class Self : public Pad8 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    char pad[0x30];
    soModuleAccesser* accesser;
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

inline WorkModule* getWork(Self* s) {
    return s->accesser->modules->work;
}

extern "C" {
extern char lbl_41_data_644[];
extern char lbl_41_data_6A8[];
extern char __RTTI__5Enemy[];
extern char __RTTI__11StageObject[];

void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_5F8A4(Self*, Cmd*, soModuleAccesser*, int);
int fn_41_A184(Arg);
int fn_41_A1C4(Arg);
unsigned long fn_41_A1E4(Arg);
float fn_41_A204(Arg);
void fn_41_11320(Self*, void*, void*, void*, int, int, int*);
void fn_41_11BCC(Self*, float, float);
}

extern "C" int fn_41_12DC4(Self* self, Cmd* cmd, soModuleAccesser* acc, int param)
{
    if (cmd->getGroup() != 0x6b)
        return fn_27_5F8A4(self, cmd, acc, param);

    signed char type = cmd->getType();
    int count = cmd->getArgNum();
    if (type <= -1 || type >= 4)
        return 0;

    switch (type) {
    case 0:
        if (count < 0 || count > 0)
            return 1;
        self->slot30();
        return 1;

    case 1:
        if (count < 0 || count > 0)
            return 1;
        self->slot31();
        return 1;

    case 2: {
        if (count < 3 || count > 3)
            return 1;

        const soArrayContractibleTable<const acCmdArgConv> list = cmd->getArgList();
        void* posture;
        void* link = __dynamic_cast(acc->modules->link, 0, lbl_41_data_644, lbl_41_data_6A8, 1);
        posture = acc->modules->posture;
        void* object = __dynamic_cast(acc->object, 0x3c, __RTTI__5Enemy, __RTTI__11StageObject, 1);

        int flag;
        if (fn_41_A1C4(getArg(list, 0)) == 5) {
            flag = getWork(self)->slot17(fn_41_A1E4(getArg(list, 0)));
        } else {
            Arg arg = getArg(list, 0);
            flag = arg.null == 1 ? 0 : arg.p->data != 0;
        }

        int value;
        if (fn_41_A1C4(getArg(list, 1)) == 5)
            value = soValueAccesser::getValueInt(acc, fn_41_A1E4(getArg(list, 1)), 0);
        else
            value = fn_41_A184(getArg(list, 1));

        int result = 0;
        if (fn_41_A1C4(getArg(list, 2)) == 5)
            result = soValueAccesser::getValueInt(acc, fn_41_A1E4(getArg(list, 2)), 0);
        else
            result = fn_41_A184(getArg(list, 2));

        fn_41_11320(self, object, link, posture, flag, value, &result);
        self->accesser->modules->work->slot5(result, 0x1000000c);
        return 1;
    }

    case 3: {
        if (count < 2 || count > 2)
            return 1;

        const soArrayContractibleTable<const acCmdArgConv> list = cmd->getArgList();
        float first;
        if (fn_41_A1C4(getArg(list, 0)) == 5)
            first = soValueAccesser::getValueFloat(acc, fn_41_A1E4(getArg(list, 0)), 0);
        else
            first = fn_41_A204(getArg(list, 0));

        float second = lbl_41_rodata_BE0;
        if (fn_41_A1C4(getArg(list, 1)) == 5)
            second = soValueAccesser::getValueFloat(acc, fn_41_A1E4(getArg(list, 1)), 0);
        else
            second = fn_41_A204(getArg(list, 1));

        fn_41_11BCC(self, first, second);
        return 1;
    }
    }

    return 0;
}

