#include <so/so_module_accesser.h>
#pragma force_active on

struct WolfArticleFloatAccesser {
    u8 prefix[0x10];
    u32 indexBase;
    u8 gap[0x4];
    float* floatArrays[1];
};

extern "C" {

float fn_125_10C98(WolfArticleFloatAccesser* self, soModuleAccesser* accesser, int index, int element) {
    return self->floatArrays[index - self->indexBase][element];
}
}
