#include <so/so_module_accesser.h>
#pragma force_active on

struct Ganon109DispatchSpeed { float x, y; };

struct Ganon109ResetContext {
    unsigned char initialized;
    Ganon109ResetContext() {
        __memclr(&initialized, sizeof(initialized));
    }
    void resetIdle(int, const Vec2f*, soModuleAccesser*) {}
};

extern "C" {
void fn_27_15FA20(int, int, soModuleAccesser*);
Ganon109DispatchSpeed fn_27_164B10(soModuleAccesser*, bool, bool);
void fn_27_160268(soModuleAccesser*);
void fn_109_E304(void*, int, const void*, soModuleAccesser*);
void fn_109_E3B8(void*, int, const void*, soModuleAccesser*);
}

extern "C" void fn_109_E200(int kind, int resetKind, soModuleAccesser* accesser) {
    if (kind <= 0x63) {
        fn_27_15FA20(kind, resetKind, accesser);
        return;
    }
    Vec2f speed;
    Ganon109DispatchSpeed returnedSpeed = fn_27_164B10(accesser, 1, 1);
    __memcpy(&speed, &returnedSpeed, sizeof(speed));
    switch (kind) {
    case 0x64: {
        Ganon109ResetContext context;
        fn_109_E304(&context, resetKind, &speed, accesser);
        break;
    }
    case 0x65: {
        Ganon109ResetContext context;
        fn_109_E3B8(&context, resetKind, &speed, accesser);
        break;
    }
    case 0x66: {
        Ganon109ResetContext context;
        context.resetIdle(resetKind, &speed, accesser);
        break;
    }
    case 0x67: {
        Ganon109ResetContext context;
        context.resetIdle(resetKind, &speed, accesser);
        break;
    }
    case 0x68: {
        Ganon109ResetContext context;
        context.resetIdle(resetKind, &speed, accesser);
        break;
    }
    default:
        return;
    }
    fn_27_160268(accesser);
}
