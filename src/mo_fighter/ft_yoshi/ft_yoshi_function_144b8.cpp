#include <so/so_module_accesser.h>
#pragma force_active on

struct Vec2 { float x, y; };

struct YoshiDispatchSpeed { float x, y; };

struct YoshiResetContext {
    unsigned char initialized;
    YoshiResetContext() {
        __memclr(&initialized, sizeof(initialized));
    }
};

extern "C" {
void fn_27_15FA20(int, int, soModuleAccesser*);
YoshiDispatchSpeed fn_27_164B10(soModuleAccesser*, bool, bool);
void fn_27_160268(soModuleAccesser*);
void fn_95_145F8(void*, int, Vec2*, soModuleAccesser*);
void fn_95_14748(void*, int, const Vec2*, soModuleAccesser*);
void fn_95_148D8(void*, int, const Vec2*, soModuleAccesser*);
void fn_95_14C74(void*, int, const Vec2*, soModuleAccesser*);
void fn_95_14F2C(void*, int, Vec2*, soModuleAccesser*);
}

extern "C" void fn_95_144B8(int kind, int resetKind, soModuleAccesser* accesser) {
    if (kind <= 0x63) {
        fn_27_15FA20(kind, resetKind, accesser);
        return;
    }
    Vec2 speed;
    YoshiDispatchSpeed returnedSpeed = fn_27_164B10(accesser, 1, 1);
    __memcpy(&speed, &returnedSpeed, sizeof(speed));
    switch (kind) {
    case 0x64: {
        YoshiResetContext context;
        fn_95_145F8(&context, resetKind, &speed, accesser);
        break;
    }
    case 0x65: {
        YoshiResetContext context;
        fn_95_14748(&context, resetKind, &speed, accesser);
        break;
    }
    case 0x66: {
        YoshiResetContext context;
        fn_95_148D8(&context, resetKind, &speed, accesser);
        break;
    }
    case 0x67: {
        YoshiResetContext context;
        fn_95_14C74(&context, resetKind, &speed, accesser);
        break;
    }
    case 0x68: {
        YoshiResetContext context;
        fn_95_14F2C(&context, resetKind, &speed, accesser);
        break;
    }
    default:
        return;
    }
    fn_27_160268(accesser);
}
