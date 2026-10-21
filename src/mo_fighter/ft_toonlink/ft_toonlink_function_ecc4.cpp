#include <so/so_module_accesser.h>
#pragma force_active on

struct ToonLinkDispatchSpeed {
    float x, y;
};

struct ToonLinkResetContext {
    unsigned char initialized;

    ToonLinkResetContext() {
        __memclr(&initialized, sizeof(initialized));
    }

    void resetIdle(int, const Vec2f*, soModuleAccesser*) {}
};

extern "C" {
void fn_27_15FA20(int, int, soModuleAccesser*);
ToonLinkDispatchSpeed fn_27_164B10(soModuleAccesser*, bool, bool);
void fn_121_EDCC(void*, int, const Vec2f*, soModuleAccesser*);
void fn_121_EF2C(void*, int, const Vec2f*, soModuleAccesser*);
void fn_121_F148(void*, int, const Vec2f*, soModuleAccesser*);
}

extern "C" void fn_121_ECC4(int kind, int resetKind, soModuleAccesser* accesser) {
    if (kind <= 0x63) {
        fn_27_15FA20(kind, resetKind, accesser);
        return;
    }

    Vec2f speed;
    ToonLinkDispatchSpeed returnedSpeed = fn_27_164B10(accesser, 1, 1);
    __memcpy(&speed, &returnedSpeed, sizeof(speed));

    switch (kind) {
    case 0x64: {
        ToonLinkResetContext context;
        fn_121_EDCC(&context, resetKind, &speed, accesser);
        break;
    }
    case 0x65: {
        ToonLinkResetContext context;
        fn_121_EF2C(&context, resetKind, &speed, accesser);
        break;
    }
    case 0x66: {
        ToonLinkResetContext context;
        fn_121_F148(&context, resetKind, &speed, accesser);
        break;
    }
    case 0x67: {
        ToonLinkResetContext context;
        context.resetIdle(resetKind, &speed, accesser);
        break;
    }
    case 0x68: {
        ToonLinkResetContext context;
        context.resetIdle(resetKind, &speed, accesser);
        break;
    }
    default:
        return;
    }
}
