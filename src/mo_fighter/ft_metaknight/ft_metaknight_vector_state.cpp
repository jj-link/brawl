#include <mt/mt_vector.h>

struct MetaKnightVectorState {
    u8 prefix[8];
    Vec2f vector08;
    Vec2f vector10;
    Vec2f vector18;
    Vec2f vector20;
    Vec2f vector28;
    u8 flag30;
    u8 flag31;
    u8 flag32;
};

extern "C" const float lbl_111_rodata_8;
extern "C" const float lbl_111_rodata_C;

#pragma dont_inline on
extern "C" Vec2f* fn_111_A628(Vec2f* destination, const Vec2f* source);
#pragma dont_inline reset

extern "C" void fn_111_A5EC() {
}

extern "C" void fn_111_A5F0(MetaKnightVectorState* state) {
    Vec2f zero(lbl_111_rodata_8, lbl_111_rodata_8);
    fn_111_A628(&state->vector08, &zero);
}

#pragma dont_inline on
extern "C" Vec2f* fn_111_A628(Vec2f* destination, const Vec2f* source) {
    destination->m_x = source->m_x;
    destination->m_y = source->m_y;
    return destination;
}
#pragma dont_inline reset

extern "C" void fn_111_A63C(MetaKnightVectorState* state) {
    Vec2f zero(lbl_111_rodata_8, lbl_111_rodata_8);
    fn_111_A628(&state->vector08,
        fn_111_A628(&state->vector10,
            fn_111_A628(&state->vector20, &zero)));
    Vec2f limit(lbl_111_rodata_C, lbl_111_rodata_C);
    fn_111_A628(&state->vector18,
        fn_111_A628(&state->vector28, &limit));
    state->flag31 = 0;
    state->flag30 = 0;
    state->flag32 = 1;
}

extern "C" void fn_111_A6D4(MetaKnightVectorState* state) {
    state->flag31 = 0;
}

extern "C" void fn_111_A6E0(MetaKnightVectorState* state) {
    state->flag31 = 1;
}
