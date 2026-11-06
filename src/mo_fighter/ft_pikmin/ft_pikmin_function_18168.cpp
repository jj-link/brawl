#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on
extern "C" unsigned long long fn_113_18DE4(void*);
extern "C" int fn_113_182BC(float);
extern "C" float fn_113_182E4(float*);
struct Pair { unsigned int x, y; };
extern "C" int fn_113_18168(void* a) {
    int kind = (*(soModuleAccesser**)((char*)a + 0x60))->getStatusModule().getStatusKind();
    bool flag;
    switch (kind) {
    case 0x1e: case 0x1f: case 0x2c: flag = true; break;
    default: flag = false; break;
    }
    if (flag == 1) return 0;
    switch (kind) {
    case 0xe: case 0xf: case 0x10: case 0x11: case 0x12: case 0x13:
    case 0x26: case 0x27: case 0x28: case 0x29: return 0;
    }
    Pair v;
    unsigned long long raw = fn_113_18DE4(a);
    v = *(Pair*)&raw;
    int result = fn_113_182BC(*(float*)&v.x);
    if (result) result = fn_113_182BC(*(float*)&v.y);
    result = result == 1;
    if (result) {
        soModuleAccesser* accesser = *(soModuleAccesser**)((char*)a + 0x60);
        soParamAccesser* params = static_cast<soParamAccesser*>(accesser->getWorkManageModule().getParamAccesser());
        float limit = params->getParamFloat(accesser, 0xfad, 0);
        result = fn_113_182E4((float*)&v) <= limit;
    }
    return result;
}