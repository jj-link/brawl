#pragma force_active on
#include <types.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>

struct Vec2 { float x, y; };
struct Pair { u32 x, y; };
struct Vec3 { float x, y, z; Vec3(const Vec3&); };
struct ModelBase { char pad[8]; };
struct ModelModule : ModelBase {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual Vec3 get(int, bool);
};
struct StatusModule {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual s32 getStatusKind();
};
struct FloatModule {
    virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10();
    virtual float f11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual float f24();
};
struct Obj {
    virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void append(const Vec2* v);
};
extern "C" {
void fn_113_12874(void*, soModuleAccesser*);
void fn_113_11B28(void*, soModuleAccesser*);
void fn_113_12C9C(void*, soModuleAccesser*);
void fn_113_130F0(void*, soModuleAccesser*);
void fn_113_1386C(void*, soModuleAccesser*);
void fn_113_13C7C(void*, soModuleAccesser*);
void fn_113_13958(void*, s32);
void fn_113_13990(void*, short);
s32 fn_113_243CC(void*);
void fn_113_24B10(void*, void*);
void fn_113_B7F0(Vec2*, const Vec3*);
void fn_113_BF8C(const Vec2*, const Vec2*, Vec2*);
unsigned long long fn_113_BFB0(const Vec2*, const Vec2*);
void fn_113_C30C(Vec2*, float, float);
extern float lbl_113_rodata_C;
}
inline Vec2 addVec(const Vec2* a, const Vec2* b) {
    Vec2 temp;
    fn_113_BF8C(a, b, &temp);
    return temp;
}
extern "C" void fn_113_C024(void* arg0) {
    char* self = (char*)arg0;
    StatusModule* st = *(StatusModule**)(*(char**)(*(char**)(self + 0x60) + 0xD8) + 0x70);
    s32 kind = st->getStatusKind();
    switch (kind) {
    case 0x33:
        fn_113_12874(self + 0x200E0, *(soModuleAccesser**)(self + 0x60));
        break;
    case 0x113:
        fn_113_11B28(self + 0x200D8, *(soModuleAccesser**)(self + 0x60));
        break;
    case 0x2A:
    case 0x2B:
    case 0x2C:
        fn_113_12C9C(self + 0x200F8, *(soModuleAccesser**)(self + 0x60));
        break;
    case 0x30:
    case 0x31:
    case 0x32:
        fn_113_130F0(self + 0x20110, *(soModuleAccesser**)(self + 0x60));
        break;
    case 0x2D:
    case 0x2E:
    case 0x2F:
        if (fn_113_243CC(self + 0x1FD08) > 0) {
            char o[0x68];
            fn_113_13958(o, 0);
            ModelModule* p = *(ModelModule**)(*(char**)(*(char**)(self + 0x60) + 0xD8) + 4);
            Vec3 sp44 = p->get(0, false);
            Vec2 sp30;
            fn_113_B7F0(&sp30, &sp44);

            p = *(ModelModule**)(*(char**)(*(char**)(self + 0x60) + 0xD8) + 4);
            Vec3 sp38 = p->get(0, false);
            Vec2 sp28;
            fn_113_B7F0(&sp28, &sp38);
            p = (ModelModule*)*(soModuleAccesser**)(self + 0x60);
            soModuleAccesser* acc = (soModuleAccesser*)p;
            float f31 = soValueAccesser::getConstantFloat(acc, 0xFA9, 0);
            float f1 = soValueAccesser::getConstantFloat(acc, 0xFA8, 0);
            Vec2 sp20;
            fn_113_C30C(&sp20, f1, f31);
            FloatModule* fm = *(FloatModule**)(*(char**)(*(char**)(self + 0x60) + 0xD8) + 0xC);
            float s = fm->f24();
            sp20.x *= s;
            sp20.y *= s;
            fm = *(FloatModule**)(*(char**)(*(char**)(self + 0x60) + 0xD8) + 0xC);
            if (fm->f11() < lbl_113_rodata_C) sp20.x = -sp20.x;
            Vec2 sp18 = addVec(&sp30, &sp20);
            reinterpret_cast<Obj*>(o)->append(&sp18);
            unsigned long long bits = fn_113_BFB0(&sp30, &sp20);
            Vec2 sp10;
            *(unsigned long long*)&sp10 = bits;
            reinterpret_cast<Obj*>(o)->append(&sp10);
            fn_113_24B10(self + 0x1FD08, o);
            fn_113_13990(o, -1);
        }
        break;
    case 0x114:
        fn_113_1386C(self + 0x20118, *(soModuleAccesser**)(self + 0x60));
        break;
    case 0x34:
    case 0x36:
    case 0x38:
        fn_113_13C7C(self + 0x20120, *(soModuleAccesser**)(self + 0x60));
        break;
    }
}