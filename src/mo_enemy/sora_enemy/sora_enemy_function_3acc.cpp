#pragma force_active on
extern "C" int getValueInt__15soValueAccesserFP16soModuleAccesserUlUl(void*, unsigned int, unsigned int);

class Obj {
public:
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
    virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
    virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
    virtual void d16(); virtual void d17();
    virtual void setA(unsigned long);
    virtual void setB(unsigned long);
};

struct Module {
    char pad[0x64];
    Obj* obj;
};

struct Self {
    char pad[0x1B4];
    Module* mod;
};

extern "C" void fn_41_3ACC(Self* self) {
    Obj* obj = self->mod->obj;
    int val = getValueInt__15soValueAccesserFP16soModuleAccesserUlUl((char*)self + 0xDC, 0x59E7, 0);
    if ((unsigned int)(val ? 1 : 0) == 1U) {
        obj->setA(0x12000003);
    } else {
        obj->setB(0x12000003);
    }
}
