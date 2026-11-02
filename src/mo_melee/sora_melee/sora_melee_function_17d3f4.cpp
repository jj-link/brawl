#pragma force_active on
typedef unsigned int u32;

class Work {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int getInt(u32 id);
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual float getFloat(u32 id);
    virtual void setFloat(u32 id, float v);
};

struct Modules {
    char pad[0x64];
    Work* work;
};

struct Accesser {
    char pad[0xD8];
    Modules* modules;
};

struct Vec2 {
    float x;
    float y;
};

extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(Accesser*, u32, u32);
extern "C" void fn_27_194458(Accesser*, Vec2*, float);
extern "C" void fn_27_17DA90(void*, Accesser*, float);
extern float lbl_27_rodata_2390;
extern float lbl_27_rodata_239C;

extern "C" void fn_27_17D3F4(void* self, Accesser* acc) {
    switch (acc->modules->work->getInt(0x2000000C)) {
    case 0: {
        Vec2 v;
        fn_27_194458(acc, &v, lbl_27_rodata_239C);
        float r = lbl_27_rodata_2390;
        if (v.x > r) {
            r = v.x * -v.y * getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(acc, 0xD7C, 0);
        }
        fn_27_17DA90(self, acc, r);
        break;
    }
    case 1: {
        Vec2 v;
        fn_27_194458(acc, &v, lbl_27_rodata_239C);
        if (v.x > lbl_27_rodata_2390) {
            float d = v.x * -v.y * getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(acc, 0xD7C, 0);
            float g = acc->modules->work->getFloat(0x21000009);
            g += d;
            acc->modules->work->setFloat(0x21000009, g);
        }
        break;
    }
    }
}
