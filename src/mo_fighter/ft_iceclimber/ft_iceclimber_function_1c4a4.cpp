#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" void fn_27_1DCC10(int kind, unsigned char* state, soModuleAccesser* accesser);
extern "C" void fn_105_1C50C(void* ctx);
extern "C" void fn_105_1C7B8(void* ctx);

extern "C" void fn_105_1C4A4(int kind, unsigned char* state, soModuleAccesser* accesser) {
    struct IceCtx {
        unsigned char flag;
    };
    if (kind <= 0x1f) {
        fn_27_1DCC10(kind, state, accesser);
        return;
    }
    switch (kind) {
    case 0x20: {
        IceCtx ctx;
        ctx.flag = 0;
        fn_105_1C50C(&ctx);
        break;
    }
    case 0x21: {
        IceCtx ctx;
        ctx.flag = 0;
        fn_105_1C7B8(&ctx);
        break;
    }
    default:
        break;
    }
}
