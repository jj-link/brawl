#include <so/so_module_accesser.h>
#pragma force_active on

struct PokeDispatchSpeed { float x, y; };
struct PokeResetContext {
    unsigned char initialized;
    PokeResetContext() {
        __memclr(&initialized, sizeof(initialized));
    }
    void resetIdle(int, const Vec2f*, soModuleAccesser*) {}
};

extern "C" {
void fn_27_15FA20(int, int, soModuleAccesser*);
PokeDispatchSpeed fn_27_164B10(soModuleAccesser*, bool, bool);
void fn_27_160268(soModuleAccesser*);
void fn_27_15FBC8(int, int, const Vec2f*, soModuleAccesser*);
void fn_116_1A740(void*, int, const void*, soModuleAccesser*);
void fn_116_1A810(void*, int, const void*, soModuleAccesser*);
void fn_116_1A98C(void*, int, const void*, soModuleAccesser*);
void fn_116_1AADC(void*, int, const void*, soModuleAccesser*);
void fn_116_1ABC4(void*, int, const void*, soModuleAccesser*);
}

extern "C" void fn_116_1A5B8(int kind, int resetKind, soModuleAccesser* accesser) {
    if (kind <= 0x63) {
        fn_27_15FA20(kind, resetKind, accesser);
        return;
    }
    Vec2f speed;
    PokeDispatchSpeed returnedSpeed = fn_27_164B10(accesser, 1, 1);
    __memcpy(&speed, &returnedSpeed, sizeof(speed));
    switch (kind) {
    case 0x64: { PokeResetContext context; fn_27_15FBC8(6, resetKind, &speed, accesser); break; }
    case 0x65: { PokeResetContext context; fn_116_1A740(&context, resetKind, &speed, accesser); break; }
    case 0x66: { PokeResetContext context; fn_116_1A810(&context, resetKind, &speed, accesser); break; }
    case 0x67: { PokeResetContext context; fn_116_1A98C(&context, resetKind, &speed, accesser); break; }
    case 0x68: { PokeResetContext context; fn_116_1AADC(&context, resetKind, &speed, accesser); break; }
    case 0x69: { PokeResetContext context; fn_116_1ABC4(&context, resetKind, &speed, accesser); break; }
    case 0x6A: { PokeResetContext context; context.resetIdle(resetKind, &speed, accesser); break; }
    case 0x6B: { PokeResetContext context; context.resetIdle(resetKind, &speed, accesser); break; }
    case 0x6C: { PokeResetContext context; context.resetIdle(resetKind, &speed, accesser); break; }
    case 0x6D: { PokeResetContext context; context.resetIdle(resetKind, &speed, accesser); break; }
    default: return;
    }
    fn_27_160268(accesser);
}
