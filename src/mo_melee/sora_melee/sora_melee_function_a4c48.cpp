#pragma force_active on

typedef unsigned int u32;
typedef unsigned char u8;

struct FlagBlock;

struct FlagHolder {
    FlagBlock* block;
    u8 padding[0x19];
    u8 flags;
};

class Array {
public:
    virtual void dummy0();
    virtual FlagHolder* at(int);
    virtual void dummy1();
    virtual int size();
};

class Module {
public:
    virtual void dummy0();
    virtual void dummy1();
    virtual void dummy2();
    virtual void dummy3();
    virtual void dummy4();
    virtual void dummy5();
    virtual void dummy6();
    virtual void dummy7();
    virtual void dummy8();
    virtual void dummy9();
    virtual void dummy10();
    virtual void dummy11();
    virtual void set(int, bool, int);

    u8 padding[0x2C];
    Array* array;
};

extern "C" bool fn_27_A7588(FlagHolder*, u32);

extern "C" void fn_27_A4C48(Module* self, int mode)
{
    int count = self->array->size();
    FlagHolder* holder;
    for (int i = 0; i < count; ++i) {
        holder = self->array->at(i);
        if ((holder->flags >> 6) & 1) {
            if (fn_27_A7588(holder, 0x80)) {
                self->set(i, mode == 0, -1);
            }
            if (fn_27_A7588(holder, 0x100)) {
                self->set(i, mode == 2, -1);
            }
        }
    }
}
