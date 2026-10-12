#include <so/so_module_accesser.h>

struct PikachuActivationContext {
    unsigned char initialized;
    PikachuActivationContext() {
        __memclr(&initialized, sizeof(initialized));
    }
    void activateIdle(void*, soModuleAccesser*) {}
};

extern "C" void fn_27_15FA20(int kind, void* state, soModuleAccesser* accesser);
extern "C" void fn_27_160268(soModuleAccesser* accesser);
extern "C" void fn_98_E608(void* context, int state, soModuleAccesser* accesser);

extern "C" void fn_98_E554(int kind, void* state, soModuleAccesser* accesser) {
    if (kind <= 99) {
        fn_27_15FA20(kind, state, accesser);
        return;
    }
    switch (kind) {
    case 100: {
        PikachuActivationContext context;
        fn_98_E608(&context, reinterpret_cast<int>(state), accesser);
        break;
    }
    case 101: {
        PikachuActivationContext context;
        context.activateIdle(state, accesser);
        break;
    }
    case 102: {
        PikachuActivationContext context;
        context.activateIdle(state, accesser);
        break;
    }
    case 103: {
        PikachuActivationContext context;
        context.activateIdle(state, accesser);
        break;
    }
    case 104: {
        PikachuActivationContext context;
        context.activateIdle(state, accesser);
        break;
    }
    default:
        return;
    }
    fn_27_160268(accesser);
}
