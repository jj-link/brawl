#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" void fn_27_1DCC10(int kind, unsigned char* state, soModuleAccesser* accesser);
extern "C" void fn_113_2A53C(unsigned char* flag, unsigned char* state, soModuleAccesser* accesser);
extern "C" void fn_113_2A840(unsigned char* flag, unsigned char* state, soModuleAccesser* accesser);

extern "C" void fn_113_2A4AC(int kind, unsigned char* state, soModuleAccesser* accesser) {
    unsigned char buf[4];

    if (kind <= 31) {
        fn_27_1DCC10(kind, state, accesser);
        return;
    }
    switch (kind) {
    case 32:
        buf[3] = 0;
        fn_113_2A53C(&buf[3], state, accesser);
        break;
    case 33:
        buf[2] = 0;
        fn_113_2A840(&buf[2], state, accesser);
        break;
    case 34:
        buf[1] = 0;
        break;
    case 35:
        buf[0] = 0;
        break;
    default:
        break;
    }
}
