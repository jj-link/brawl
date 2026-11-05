#pragma force_active on

extern const float lbl_40_rodata_A8;

struct Data {
    int a;
    int b;
    float c;
    int d;
    int e;
    int f;
};

class Class_5648 {
public:
    virtual void fn_40_215A4();
    virtual void fn_40_20A6C();
    virtual void fn_40_20A7C();
    virtual Data* fn_40_1E5E0(int);
};

class Class_6C68 {
public:
    virtual void fn_40_215A4();
    virtual void fn_40_20A6C();
    virtual void fn_40_20A7C();
    virtual Data* fn_40_24BA4(int);
};

class Class_83C8 {
public:
    virtual void fn_40_295F8();
    virtual void fn_40_28A18();
    virtual void fn_40_28A28();
    virtual Data* fn_40_28908(int);
};

class Class_CEC8 {
public:
    virtual void fn_40_215A4();
    virtual void fn_40_20A6C();
    virtual void fn_40_20A7C();
    virtual Data* fn_40_30C08(int);
};

class Class_D270 {
public:
    virtual void fn_40_295F8();
    virtual void fn_40_28A18();
    virtual void fn_40_28A28();
    virtual Data* fn_40_30D68(int);
};

struct Owner {
    char pad[0x1d8];
    Class_5648* const object;
};

extern "C" void fn_40_7848(Data* out, const Owner* owner, int id) {
    Data def;
    def.a = 60;
    def.b = def.a;
    def.c = lbl_40_rodata_A8;
    def.d = 180;
    def.e = 240;
    def.f = 120;

    Data* p = owner->object->fn_40_1E5E0(id);
    out->a = (p ? p : &def)->a;
    out->b = (p ? p : &def)->b;
    out->c = (p ? p : &def)->c;
    out->d = (p ? p : &def)->d;
    out->e = (p ? p : &def)->e;
    out->f = (p ? p : &def)->f;
}
