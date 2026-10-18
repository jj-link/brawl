#include <so/so_module_accesser.h>
#pragma force_active on

struct PikminDispatchSpeed { float x, y; };
struct PikminResetContext {
    unsigned char initialized;
    PikminResetContext() {
        __memclr(&initialized, sizeof(initialized));
    }
};
extern "C" {
void fn_27_15FA20(int, int, soModuleAccesser*);
PikminDispatchSpeed fn_27_164B10(soModuleAccesser*, bool, bool);
void fn_27_160268(soModuleAccesser*);
void fn_113_12588(void*, int, const Vec2f*, soModuleAccesser*);
}

extern "C" void fn_113_124E8(int kind, int resetKind, soModuleAccesser* accesser) {
    if (kind <= 0x63) {
        fn_27_15FA20(kind, resetKind, accesser);
        return;
    }
    Vec2f speed;
    PikminDispatchSpeed returnedSpeed = fn_27_164B10(accesser, 1, 1);
    __memcpy(&speed, &returnedSpeed, sizeof(speed));
    switch (kind) {
    case 0x64: {
        PikminResetContext context;
        fn_113_12588(&context, resetKind, &speed, accesser);
        break;
    }
    default:
        return;
    }
    fn_27_160268(accesser);
}
