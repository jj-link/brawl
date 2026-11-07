#include <so/so_module_accesser.h>
#pragma force_active on

struct LinkDispatchSpeed { float x, y; };
struct LinkResetContext {
    unsigned char initialized;
    LinkResetContext() {
        __memclr(&initialized, sizeof(initialized));
    }
};

extern "C" {
void fn_27_15FA20(int, int, soModuleAccesser*);
LinkDispatchSpeed fn_27_164B10(soModuleAccesser*, bool, bool);
void fn_27_160268(soModuleAccesser*);
void fn_93_EE14(void*, int, const void*, soModuleAccesser*);
void fn_93_EF74(void*, int, const void*, soModuleAccesser*);
void fn_93_F190(void*, int, const void*, soModuleAccesser*);
}

extern "C" void fn_93_ECC8(int kind, int resetKind, soModuleAccesser* accesser) {
    if (kind <= 0x63) {
        fn_27_15FA20(kind, resetKind, accesser);
        return;
    }
    Vec2f speed;
    LinkDispatchSpeed returnedSpeed = fn_27_164B10(accesser, 1, 1);
    __memcpy(&speed, &returnedSpeed, sizeof(speed));
    switch (kind) {
    case 0x64: {
        LinkResetContext context;
        fn_93_EE14(&context, resetKind, &speed, accesser);
        break;
    }
    case 0x65: {
        LinkResetContext context;
        fn_93_EF74(&context, resetKind, &speed, accesser);
        break;
    }
    case 0x66: {
        LinkResetContext context;
        fn_93_F190(&context, resetKind, &speed, accesser);
        break;
    }
    case 0x67: {
        LinkResetContext context;
        break;
    }
    case 0x68: {
        LinkResetContext context;
        break;
    }
    case 0x69: {
        LinkResetContext context;
        break;
    }
    case 0x6A: {
        LinkResetContext context;
        break;
    }
    case 0x6B: {
        LinkResetContext context;
        break;
    }
    case 0x6C: {
        LinkResetContext context;
        break;
    }
    case 0x6D: {
        LinkResetContext context;
        break;
    }
    default:
        return;
    }
    fn_27_160268(accesser);
}
