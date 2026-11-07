#include <so/so_module_accesser.h>
#pragma force_active on

struct CaptainDispatchSpeed { float x, y; };
struct CaptainResetContext {
    unsigned char initialized;
    CaptainResetContext() {
        __memclr(&initialized, sizeof(initialized));
    }
};

extern "C" {
void fn_27_15FA20(int, int, soModuleAccesser*);
CaptainDispatchSpeed fn_27_164B10(soModuleAccesser*, bool, bool);
void fn_27_160268(soModuleAccesser*);
void fn_100_CADC(void*, int, const Vec2f*, soModuleAccesser*);
void fn_100_CC94(void*, int, const void*, soModuleAccesser*);
}

extern "C" void fn_100_C9A4(int kind, int resetKind, soModuleAccesser* accesser) {
    if (kind <= 0x63) {
        fn_27_15FA20(kind, resetKind, accesser);
        return;
    }
    Vec2f speed;
    CaptainDispatchSpeed returnedSpeed = fn_27_164B10(accesser, 1, 1);
    __memcpy(&speed, &returnedSpeed, sizeof(speed));
    switch (kind) {
    case 0x64: {
        CaptainResetContext context;
        fn_100_CADC(&context, resetKind, &speed, accesser);
        break;
    }
    case 0x65: {
        CaptainResetContext context;
        fn_100_CC94(&context, resetKind, &speed, accesser);
        break;
    }
    case 0x66: {
        CaptainResetContext context;
        break;
    }
    case 0x67: {
        CaptainResetContext context;
        break;
    }
    case 0x68: {
        CaptainResetContext context;
        break;
    }
    case 0x69: {
        CaptainResetContext context;
        break;
    }
    case 0x6A: {
        CaptainResetContext context;
        break;
    }
    case 0x6B: {
        CaptainResetContext context;
        break;
    }
    case 0x6C: {
        CaptainResetContext context;
        break;
    }
    case 0x6D: {
        CaptainResetContext context;
        break;
    }
    default:
        return;
    }
    fn_27_160268(accesser);
}
