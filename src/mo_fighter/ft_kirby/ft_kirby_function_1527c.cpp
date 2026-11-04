#pragma force_active on
extern "C" {
extern const char lbl_96_data_608[];
extern const char lbl_96_data_68D8[];
extern float lbl_96_rodata_4C;
extern float lbl_96_rodata_48;

void* __dynamic_cast(void*, long, const void*, const void*, short);

struct Values {
    char pad[8];
    int value;
};

struct Info {
    char pad[4];
    Values* values;
};

Info* fn_96_AF98(void*);
}

class Work {
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void setFloat(float, int);
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void onFlag(int);
};

struct Modules {
    char pad[0x64];
    Work* work;
};

struct Accesser {
    char pad0[8];
    void* object;
    char pad1[0xcc];
    Modules* modules;
};

extern "C" void fn_96_1527C(void*, Accesser* a) {
    Info* info = fn_96_AF98(
        __dynamic_cast(a->object, 0x3c, lbl_96_data_608, lbl_96_data_68D8, 1));
    Work* work = a->modules->work;

    float value = (float)info->values->value;
    if (value > lbl_96_rodata_4C) {
        work->onFlag(0x12000003);
        work->setFloat(value, 0x11000000);
        work->setFloat(lbl_96_rodata_48, 0x11000001);
    }
}
