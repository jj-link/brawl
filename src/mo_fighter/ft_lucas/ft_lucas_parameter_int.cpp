#include <ft/ft_extend_param_accesser.h>
#include <types.h>

// ftExtendParamAccesserEx<3999, 34, 24999, 9> stores two variations.
// Keep the accessor's four-word base and the original unchecked indices.
struct LucasIntegerParameterStorage {
    u32 base[4];
    const float* floats[2][35];
    const s32* ints[2][10];
};
static_assert(sizeof(LucasIntegerParameterStorage) ==
              sizeof(ftExtendParamAccesserEx<3999, 34, 24999, 9>),
              "Lucas parameter storage must retain its accessor layout");

extern "C" s32 fn_114_D220();

extern "C" s32 fn_114_D22C(const LucasIntegerParameterStorage* parameters,
                          soModuleAccesser*, s32 parameter, s32 element) {
    return parameters->ints[fn_114_D220()][parameter - 24000][element];
}
