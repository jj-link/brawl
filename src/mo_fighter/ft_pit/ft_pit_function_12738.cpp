#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
void fn_27_1DCC10(int kind, unsigned char* state, soModuleAccesser* accesser);
void fn_112_127D8(unsigned char* context, int state, soModuleAccesser* accesser);
void fn_112_12884(unsigned char* context, int state, soModuleAccesser* accesser);
void fn_112_12990(unsigned char* context, int state, soModuleAccesser* accesser);
void fn_112_129E4(unsigned char* context, int state, soModuleAccesser* accesser);
}

struct PitContext {
    unsigned char c;
    unsigned char d;
    unsigned char e;
    unsigned char f;
};

extern "C" void fn_112_12738(int kind, void* state, soModuleAccesser* accesser) {
    if (kind <= 31) {
        fn_27_1DCC10(kind, (unsigned char*)state, accesser);
        return;
    }
    PitContext context;
    switch (kind) {
    case 32:
        context.f = 0;
        fn_112_127D8(&context.f, (int)state, accesser);
        break;
    case 33:
        context.e = 0;
        fn_112_12884(&context.e, (int)state, accesser);
        break;
    case 34:
        context.d = 0;
        fn_112_12990(&context.d, (int)state, accesser);
        break;
    case 35:
        context.c = 0;
        fn_112_129E4(&context.c, (int)state, accesser);
        break;
    default:
        return;
    }
}
