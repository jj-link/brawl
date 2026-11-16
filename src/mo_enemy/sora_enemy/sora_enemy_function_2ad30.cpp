#pragma force_active on
#include <types.h>

struct acCmdArgConv { s32 argType; s32 data; };
template <class T> class ArrayBase {
public:
    virtual void v0();
    virtual T& at(s32 index);
    virtual const T& at(s32 index) const;
    virtual void v3();
    virtual void v4();
    virtual ~ArrayBase();
};
template <class T> class soArrayContractibleTable : public ArrayBase<T> {
public:
    virtual ~soArrayContractibleTable();
    char data[20];
};
class Cmd {
public:
    virtual void v0();
    virtual s8 getGroup();
    virtual s8 getType();
    virtual s32 getArgNum();
    virtual void v4();
    virtual soArrayContractibleTable<const acCmdArgConv> getArgList();
};
struct Pad8 { s32 a; s32 b; };
class Acc : public Pad8 {
public:
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
    virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
    virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
    virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23();
    virtual void f24(); virtual void f25(); virtual void f26(); virtual void f27();
    virtual void f28(); virtual void f29(); virtual void f30(); virtual void f31();
    virtual s32 f32(s32 value);
};
class Ctx {
public:
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual void f8(); virtual void f9();
};
struct Arg {
    const acCmdArgConv* p;
    u8 null;
    Arg(const acCmdArgConv* q) : p(q), null(0) {}
};
#pragma inline_depth(8)
#pragma inline_max_size(1000)
inline Arg getArg(const ArrayBase<const acCmdArgConv>& list, s32 index) {
    Arg arg(&list.at(index));
    return arg;
}
extern "C" s32 fn_27_69ED4(void*, Cmd*, void*, s32);
extern "C" s32 fn_41_A184(Arg);
extern "C" void fn_41_2A888(void*, s32, s32, s32);
extern "C" s32 fn_41_2AD30(void* self, Cmd* cmd, void* accesser, s32 arg3) {
    if (cmd->getGroup() != 0x6c)
        return fn_27_69ED4(self, cmd, accesser, arg3);
    s8 kind = cmd->getType();
    s32 count = cmd->getArgNum();
    if (kind <= -1 || kind >= 2)
        return fn_27_69ED4(self, cmd, accesser, arg3);
    switch (kind) {
    case 0:
    case 1:
        goto process_args;
    default:
        goto false_result;
    }
process_args:
    {
        if (count < 2 || count > 3)
            return 1;
        soArrayContractibleTable<const acCmdArgConv> list = cmd->getArgList();
        s32 first = fn_41_A184(getArg(list, 0));
        Acc* object;
        s32 second = -1;
        if (kind == 0) {
            second = fn_41_A184(getArg(list, 1));
        } else if (kind == 1) {
            object = *(Acc**)(*(u8**)((u8*)accesser + 0xd8) + 4);
            Arg arg = getArg(list, 1);
            s32 value = arg.null == 1 ? 0 : arg.p->data;
            second = object->f32(value);
        }
        s32 flag = 1;
        if (count == 3) {
            Arg arg = getArg(list, 2);
            if (arg.null == 1)
                flag = 0;
            else
                flag = arg.p->data != 0;
        }
        Ctx* ctx = *(Ctx**)(*(u8**)(*(u8**)((u8*)self + 0x1c) + 0xd8) + 0xc);
        ctx->f9();
        fn_41_2A888(self, first, second, flag);
        return 1;
    }
false_result:
    return 0;
}