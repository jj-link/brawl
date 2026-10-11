#include <so/so_module_accesser.h>

struct LuigiDispatchSpeed { float x, y; };
struct LuigiResetContext {
    unsigned char initialized;
    LuigiResetContext() {
        __memclr(&initialized, sizeof(initialized));
    }
    void resetIdle(int, const Vec2f*, soModuleAccesser*) {}
};
extern "C" {
void fn_27_15FA20(int, int, soModuleAccesser*);
LuigiDispatchSpeed fn_27_164B10(soModuleAccesser*, bool, bool);
void fn_27_160268(soModuleAccesser*);
void fn_99_BD80(void*, int, const void*, soModuleAccesser*);
void fn_99_BE98(void*, int, const void*, soModuleAccesser*);
void fn_99_BFB0(void*, int, const void*, soModuleAccesser*);
void fn_99_C22C(void*, int, const void*, soModuleAccesser*);
void fn_99_C338(void*, int, const void*, soModuleAccesser*);
void fn_99_C4C8(void*, int, const void*, soModuleAccesser*);
void fn_99_C620(void*, int, const void*, soModuleAccesser*);
void fn_99_C7A0(void*, int, const void*, soModuleAccesser*);
}

extern "C" void fn_99_BBD0(int kind, int resetKind, soModuleAccesser* accesser) {
    if (kind <= 0x63) {
        fn_27_15FA20(kind, resetKind, accesser);
        return;
    }
    Vec2f speed;
    LuigiDispatchSpeed returnedSpeed = fn_27_164B10(accesser, 1, 1);
    __memcpy(&speed, &returnedSpeed, sizeof(speed));
    switch (kind) {
    case 0x64: {
        LuigiResetContext context;
        fn_99_BD80(&context, resetKind, &speed, accesser);
        break;
    }
    case 0x65: {
        LuigiResetContext context;
        fn_99_BE98(&context, resetKind, &speed, accesser);
        break;
    }
    case 0x66: {
        LuigiResetContext context;
        fn_99_BFB0(&context, resetKind, &speed, accesser);
        break;
    }
    case 0x67: {
        LuigiResetContext context;
        fn_99_C22C(&context, resetKind, &speed, accesser);
        break;
    }
    case 0x68: {
        LuigiResetContext context;
        fn_99_C338(&context, resetKind, &speed, accesser);
        break;
    }
    case 0x69: {
        LuigiResetContext context;
        fn_99_C4C8(&context, resetKind, &speed, accesser);
        break;
    }
    case 0x6a: {
        LuigiResetContext context;
        fn_99_C620(&context, resetKind, &speed, accesser);
        break;
    }
    case 0x6b: {
        LuigiResetContext context;
        fn_99_C7A0(&context, resetKind, &speed, accesser);
        break;
    }
    case 0x6c: {
        LuigiResetContext context;
        context.resetIdle(resetKind, &speed, accesser);
        break;
    }
    case 0x6d: {
        LuigiResetContext context;
        context.resetIdle(resetKind, &speed, accesser);
        break;
    }
    default:
        return;
    }
    fn_27_160268(accesser);
}
