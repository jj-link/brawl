#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;

struct FlagHolder {
    u8 padding[0x1D];
    u8 flags;
};

class Array {
public:
    virtual void v0();
    virtual FlagHolder* at(s32);
    virtual void v2();
    virtual s32 size();
};

class Module {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10(s32);
    virtual void v11();
    virtual void v12(s32, s32, s32);
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30(s32);

    u8 padding[0x2C];
    Array* array;
};

extern "C" bool fn_27_A7588(FlagHolder*, u32);

extern "C" void fn_27_A4B04(Module* self) {
    s32 count = self->array->size();
    FlagHolder* holder;
    for (s32 i = 0; i < count; i++) {
        holder = self->array->at(i);
        if (((holder->flags >> 6) & 1) &&
            fn_27_A7588(holder, 0x10)) {
            self->v12(i, 0, -1);
        } else if (((holder->flags >> 6) & 1) &&
                   fn_27_A7588(holder, 0x20)) {
            self->v12(i, 1, -1);
        }
        holder->flags = holder->flags & 0xFFFFFFEF;
    }
    self->v30(-1);
    self->v10(1);
}
