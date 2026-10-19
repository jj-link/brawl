#pragma force_active on

struct Vec2f {
    float x;
    float y;
};

class ModuleAccessor {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void* get(int);
};

class Module {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int getStatus(int);
};

class CastResult {
public:
    virtual void v0();
    virtual void v1();
    virtual Vec2f getVector();
};

extern "C" {
extern const char lbl_96_data_608[];
extern const char lbl_96_data_68D8[];
extern const char lbl_96_data_B09C[];
extern const char lbl_96_data_5E00[];
extern const float lbl_96_rodata_30;
extern const float lbl_96_rodata_28;

void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_96_AF98(void*);

void fn_96_13AC8(void*, char* self) {
    void* cast1 = __dynamic_cast(
        *(void**)(self + 8), 0x3c,
        lbl_96_data_608, lbl_96_data_68D8, 1);
    void* info = fn_96_AF98(cast1);

    char* entity = *(char**)(self + 0xd8);
    Module* module = (Module*)*(char**)(entity + 0x64);
    ModuleAccessor* accessor = (ModuleAccessor*)*(char**)(entity + 0x7c);
    void* object = accessor->get(0);
    CastResult* target = (CastResult*)__dynamic_cast(
        object, 0, lbl_96_data_B09C, lbl_96_data_5E00, 1);

    if (module->getStatus(0x20000002) == 2) {
        Vec2f speed = target->getVector();
        float value = speed.y;
        float selected = lbl_96_rodata_30;
        if (value > lbl_96_rodata_28)
            selected = **(float**)((char*)info + 8);
        *(float*)((char*)target + 0x40) = selected;
    }
}
}