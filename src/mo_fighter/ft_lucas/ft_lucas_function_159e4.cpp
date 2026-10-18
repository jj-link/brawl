#include <types.h>
#pragma force_active on

struct LucasVec4 {
    f32 v[4];
};

extern "C" f32 fn_114_159E4(const f32* coeffs);

extern "C" f32 fn_114_159E4(const f32* coeffs) {
    return coeffs[2] * coeffs[3];
}
