#pragma force_active on

typedef unsigned int u32;

#define SLOT(n) virtual void slot##n();

class Object_vptr_0 {
public:
    SLOT(0) SLOT(1) SLOT(2) SLOT(3) SLOT(4) SLOT(5)
    virtual int slot6();
    SLOT(7) SLOT(8) SLOT(9) SLOT(10) SLOT(11) SLOT(12)
    SLOT(13) SLOT(14)
};

struct Object_vptr_3c_base {
    char pad[0x3c];
};

class Object_vptr_3c : public Object_vptr_3c_base {
public:
    SLOT(0) SLOT(1) SLOT(2) SLOT(3) SLOT(4)
    SLOT(5) SLOT(6) SLOT(7) SLOT(8) SLOT(9)
    SLOT(10)
    virtual void processCamera();
    SLOT(12) SLOT(13) SLOT(14) SLOT(15) SLOT(16)
    virtual void renderOpa();
    SLOT(18) SLOT(19) SLOT(20)
    virtual void init();
    SLOT(22) SLOT(23) SLOT(24) SLOT(25) SLOT(26)
    SLOT(27) SLOT(28) SLOT(29) SLOT(30) SLOT(31)
    SLOT(32) SLOT(33) SLOT(34) SLOT(35) SLOT(36)
    SLOT(37) SLOT(38) SLOT(39)
    virtual int slot40();
};

#undef SLOT

struct Modules {
    char pad[0xc0];
    Object_vptr_0* object;
};

struct Context {
    char pad[8];
    Object_vptr_3c* object;
    char pad2[0xcc];
    Modules* modules;
};

class soNullable {
public:
    virtual void isNull();
    virtual void fn_27_14DE5C();
    virtual void fn_27_7FB00();
    virtual void fn_27_7FAFC();
    virtual void fn_27_7FAF8();
    virtual void fn_27_7FAF4();
    virtual void fn_27_7FAF0();
    virtual void fn_27_7FAEC();
    virtual void fn_27_14DE4C();
    virtual void fn_27_8D3C();
    virtual void fn_27_14D834();
    virtual void fn_27_8D34();
    virtual void fn_27_14D910();
    virtual void fn_27_14D9E8();
    virtual int fn_27_14DCD4() const;

    char pad[4];
    Context* context;
};

extern "C" int g_ftCommonDataAccesser;
extern "C" u32 fn_27_1457C4(int*, int, int);

extern "C" int fn_27_14DCEC(const soNullable* self) {
    u32 kind;
    Object_vptr_0* object = self->context->modules->object;
    kind = self->context->object->slot40();

    if (fn_27_1457C4(&g_ftCommonDataAccesser, object->slot6(), kind) != 0xffff) {
        return 1;
    }
    return self->fn_27_14DCD4();
}
