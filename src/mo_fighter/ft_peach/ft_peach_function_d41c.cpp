#include <types.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

struct PeachDispatchSpeed { float x, y; };

struct PeachResetContext {
    unsigned char initialized;
    PeachResetContext() {
        __memclr(&initialized, sizeof(initialized));
    }
};

class PeachVecSource {
public:
    virtual void m1();
    virtual void m2();
    virtual PeachDispatchSpeed m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual int m23();
};

extern f32 lbl_103_rodata_10;

struct PeachTmp {
    float x, y;
    PeachTmp(const PeachDispatchSpeed& v, float k) {
        x = v.x * k;
        y = v.y * k;
    }
};

static inline void peachCopy(PeachDispatchSpeed* dst, const PeachTmp& t) {
    __memcpy(dst, &t, sizeof(PeachTmp));
}

extern "C" {
void fn_27_15FA20(int, void*, soModuleAccesser*);
unsigned long long fn_27_164B10(soModuleAccesser*, bool, bool);
void fn_27_160268(soModuleAccesser*);
Vec2f* fn_103_C174(Vec2f*, const Vec2f*);
void fn_103_D730(void*, void*, const void*, soModuleAccesser*);
void fn_103_D818(void*, void*, const void*, soModuleAccesser*);
void fn_103_D870(void*, void*, const void*, soModuleAccesser*);
void fn_103_D96C(void*, void*, const void*, soModuleAccesser*);
void fn_103_DAEC(void*, void*, const void*, soModuleAccesser*);
void fn_103_DB98(void*, void*, const void*, soModuleAccesser*);
void fn_103_DD58(void*, void*, const void*, soModuleAccesser*);
void fn_103_DE7C(void*, void*, const void*, soModuleAccesser*);
void fn_103_DF78(void*, void*, const void*, soModuleAccesser*);
void fn_103_E0AC(void*, void*, const void*, soModuleAccesser*);
void fn_103_E27C(void*, void*, const void*, soModuleAccesser*);
}

extern "C" void fn_103_D41C(int kind, void* arg1, soModuleAccesser* accesser) {
    Vec2f speed;
    PeachVecSource* status = *(PeachVecSource**)((char*)*(void**)((char*)accesser + 0xd8) + 0x7c);
    if (status->m23() == 0x6a) {
        PeachResetContext ctx1;
        PeachVecSource* src1 = (PeachVecSource*)((char*)arg1 + 0x6c);
        PeachDispatchSpeed v1 = src1->m3();
        float c1 = soValueAccesser::getConstantFloat(accesser, 0xfb3, 0);
        *(float*)((char*)src1 + 0xc) = v1.y / c1;
        PeachResetContext ctx2;
        PeachVecSource* src2 = (PeachVecSource*)((char*)arg1 + 0xa0);
        float c2 = soValueAccesser::getConstantFloat(accesser, 0xfb2, 0);
        PeachDispatchSpeed out;
        PeachDispatchSpeed v2 = src2->m3();
        float scale = lbl_103_rodata_10 / c2;
        peachCopy(&out, PeachTmp(v2, scale));
        fn_103_C174((Vec2f*)((char*)src2 + 8), (Vec2f*)&out);
    }
    if (kind <= 0x63) {
        fn_27_15FA20(kind, arg1, accesser);
        return;
    }
    unsigned long long returnedSpeed = fn_27_164B10(accesser, 1, 1);
    __memcpy(&speed, &returnedSpeed, sizeof(speed));
    switch (kind) {
    case 0x64: {
        PeachResetContext context;
        fn_103_D730(&context, arg1, &speed, accesser);
        break;
    }
    case 0x65: {
        PeachResetContext context;
        fn_103_D818(&context, arg1, &speed, accesser);
        break;
    }
    case 0x66: {
        PeachResetContext context;
        fn_103_D870(&context, arg1, &speed, accesser);
        break;
    }
    case 0x67: {
        PeachResetContext context;
        fn_103_D96C(&context, arg1, &speed, accesser);
        break;
    }
    case 0x68: {
        PeachResetContext context;
        fn_103_DAEC(&context, arg1, &speed, accesser);
        break;
    }
    case 0x69: {
        PeachResetContext context;
        fn_103_DB98(&context, arg1, &speed, accesser);
        break;
    }
    case 0x6a: {
        PeachResetContext context;
        fn_103_DD58(&context, arg1, &speed, accesser);
        break;
    }
    case 0x6b: {
        PeachResetContext context;
        fn_103_DE7C(&context, arg1, &speed, accesser);
        break;
    }
    case 0x6c: {
        PeachResetContext context;
        fn_103_DF78(&context, arg1, &speed, accesser);
        break;
    }
    case 0x6d: {
        PeachResetContext context;
        fn_103_E0AC(&context, arg1, &speed, accesser);
        break;
    }
    case 0x6e: {
        PeachResetContext context;
        fn_103_E27C(&context, arg1, &speed, accesser);
        break;
    }
    case 0x6f: {
        PeachResetContext context;
        break;
    }
    case 0x70: {
        PeachResetContext context;
        break;
    }
    case 0x71: {
        PeachResetContext context;
        break;
    }
    default:
        return;
    }
    fn_27_160268(accesser);
}
