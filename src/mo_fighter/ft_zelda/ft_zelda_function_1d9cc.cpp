#include <so/so_module_accesser.h>
#pragma force_active on

struct ZeldaDispatchSpeed { float x, y; };

struct ZeldaResetContext {
    unsigned char initialized;
    ZeldaResetContext() {
        __memclr(&initialized, sizeof(initialized));
    }
};

extern "C" {
void fn_27_15FA20(int, int, soModuleAccesser*);
ZeldaDispatchSpeed fn_27_164B10(soModuleAccesser*, bool, bool);
void fn_104_1DAE8(void*, int, const Vec2f*, soModuleAccesser*);
void fn_104_1DB90(void*, int, const Vec2f*, soModuleAccesser*);
void fn_104_1DCBC(void*, int, const Vec2f*, soModuleAccesser*);
void fn_104_1DD90(void*, int, const Vec2f*, soModuleAccesser*);
}

extern "C" void fn_104_1D9CC(int kind, int resetKind, soModuleAccesser* accesser) {
    if (kind <= 0x63) {
        fn_27_15FA20(kind, resetKind, accesser);
        return;
    }

    Vec2f speed;
    ZeldaDispatchSpeed returnedSpeed = fn_27_164B10(accesser, 1, 1);
    __memcpy(&speed, &returnedSpeed, sizeof(speed));

    switch (kind) {
    case 0x64: {
        ZeldaResetContext context;
        fn_104_1DAE8(&context, resetKind, &speed, accesser);
        break;
    }
    case 0x65: {
        ZeldaResetContext context;
        fn_104_1DB90(&context, resetKind, &speed, accesser);
        break;
    }
    case 0x66: {
        ZeldaResetContext context;
        fn_104_1DCBC(&context, resetKind, &speed, accesser);
        break;
    }
    case 0x67: {
        ZeldaResetContext context;
        fn_104_1DD90(&context, resetKind, &speed, accesser);
        break;
    }
    case 0x68: {
        ZeldaResetContext context;
        break;
    }
    default:
        return;
    }
}
