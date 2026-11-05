#include <so/so_module_accesser.h>
#pragma force_active on

struct WarioDispatchSpeed { float x, y; };
struct WarioResetContext {
    unsigned char initialized;
    WarioResetContext() { __memclr(&initialized, sizeof(initialized)); }
    void resetIdle(int, const Vec2f*, soModuleAccesser*) {}
};
extern "C" {
void fn_27_15FA20(int, int, soModuleAccesser*);
WarioDispatchSpeed fn_27_164B10(soModuleAccesser*, bool, bool);
void fn_27_160268(soModuleAccesser*);
void fn_110_210D8(void*, int, const Vec2f*, soModuleAccesser*);
}
extern "C" void fn_110_20FE8(int kind, int resetKind, soModuleAccesser* accesser) {
    if (kind <= 0x63) {
        fn_27_15FA20(kind, resetKind, accesser);
        return;
    }
    Vec2f speed;
    WarioDispatchSpeed returnedSpeed = fn_27_164B10(accesser, 1, 1);
    __memcpy(&speed, &returnedSpeed, sizeof(speed));
    switch (kind) {
    case 0x64: {
        WarioResetContext context;
        fn_110_210D8(&context, resetKind, &speed, accesser);
        break;
    }
    case 0x65: {
        WarioResetContext context;
        context.resetIdle(resetKind, &speed, accesser);
        break;
    }
    case 0x66: {
        WarioResetContext context;
        context.resetIdle(resetKind, &speed, accesser);
        break;
    }
    case 0x67: {
        WarioResetContext context;
        context.resetIdle(resetKind, &speed, accesser);
        break;
    }
    case 0x68: {
        WarioResetContext context;
        context.resetIdle(resetKind, &speed, accesser);
        break;
    }
    default:
        return;
    }
    fn_27_160268(accesser);
}