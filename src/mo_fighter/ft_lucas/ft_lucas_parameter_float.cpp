#include <ft/ft_extend_param_accesser.h>
#include <types.h>

// ftExtendParamAccesserEx<3999, 34, 24999, 9> stores two variations.
// Keep the accessor's four-word base and the original unchecked indices.
struct LucasParameterStorage {
    u32 base[4];
    const float* floats[2][35];
    const s32* ints[2][10];
};
static_assert(sizeof(LucasParameterStorage) ==
              sizeof(ftExtendParamAccesserEx<3999, 34, 24999, 9>),
              "Lucas parameter storage must retain its accessor layout");

extern "C" s32 fn_114_D220();

extern "C" float fn_114_D1C8(const LucasParameterStorage* parameters,
                            soModuleAccesser*, s32 parameter, s32 element) {
    return parameters->floats[fn_114_D220()][parameter - 4000][element];
}
