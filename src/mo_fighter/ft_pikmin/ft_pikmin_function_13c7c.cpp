#pragma force_active on
#pragma scheduling off
#pragma peephole on
#include <so/so_value_accesser.h>

struct Vec2 {
    float x, y;

    Vec2 operator+(const Vec2& other) const {
        Vec2 result;
        result.x = x + other.x;
        result.y = y + other.y;
        return result;
    }
};

struct Ret {
    float x, y;
    Ret(const Ret&);
};

struct Obj;

struct ObjVtable {
    char pad[0x30];
    void (*append)(Obj*, const Vec2*);
};

struct Obj {
    ObjVtable* vt;
    void* vt2;
    unsigned int flags;
    Vec2 items[1];
};

struct ObjInterface {
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
    virtual void append(const Vec2*);
};

struct Wrapper {
    int pad;
    Obj obj;
};

struct Class_6CDC_base {
    char pad[0x34];
};

class Class_6CDC : public Class_6CDC_base {
public:
    virtual void fn_113_12414();
    virtual void fn_113_11EBC();
    virtual void fn_113_11ECC();
    virtual void fn_113_11E74();
    virtual void fn_113_12484();
    virtual void fn_113_11C04();
    virtual void fn_113_11FD0();
    virtual void fn_113_12084();
    virtual void fn_113_123CC();
    virtual void fn_113_11EDC();
    virtual void fn_113_11C60(const Vec2*);
};

struct Base {
    char pad[8];
};

struct Module : Base {
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
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual Ret get(int, bool);
};

struct Posture {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual float facing();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual float scale();
};

struct Mid {
    char pad[4];
    Module* module;
    char pad2[4];
    Posture* posture;
};

struct Arg {
    char pad[0xd8];
    Mid* mid;
};

struct Self {
    char pad[4];
    void* manager;
};

extern "C" int fn_113_243CC(void*);
extern "C" void fn_113_24B10(void*, Obj*);
extern "C" void* fn_113_11D54(void*, short);
extern "C" char lbl_113_data_6CD4[];
extern "C" const float lbl_113_rodata_4C;

extern "C" void fn_113_13C7C(Self* self, Arg* arg) {
    if (fn_113_243CC(self->manager) > 0) {
        int zero = 0;
        Ret v = arg->mid->module->get(zero, zero);
        Vec2 pos;
        pos.x = v.x;
        pos.y = v.y;

        Wrapper wrapper;
        wrapper.obj.vt = (ObjVtable*)lbl_113_data_6CD4;
        wrapper.obj.vt2 = lbl_113_data_6CD4 + 0x48;
        wrapper.obj.flags &= 0x1ffffff;
        Vec2* p = wrapper.obj.items;
        do {
            ++p;
        } while (p < wrapper.obj.items + 1);

        float y = soValueAccesser::getConstantFloat(
            (soModuleAccesser*)arg, 0xfab, 0);
        Vec2 offset;
        offset.x = soValueAccesser::getConstantFloat(
            (soModuleAccesser*)arg, 0xfaa, 0);
        offset.y = y;

        if (arg->mid->posture->facing() < lbl_113_rodata_4C)
            offset.x = -offset.x;

        float scale = arg->mid->posture->scale();
        offset.x *= scale;
        offset.y *= scale;

        Vec2 out = pos + offset;
        ((ObjInterface*)&wrapper.obj)->append(&out);

        fn_113_24B10(self->manager, &wrapper.obj);
        fn_113_11D54(&wrapper.obj, 0);
    }
}
