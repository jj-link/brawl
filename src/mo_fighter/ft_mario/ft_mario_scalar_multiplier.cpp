// Scalar multiplier state used by the Mario module's generated interface.
struct MarioScalarMultiplier {
    unsigned char prefix[8];
    float multiplier;
    float value;
};
extern "C" const float lbl_91_rodata_30;
extern "C" void fn_91_10174(MarioScalarMultiplier* state) {
    state->multiplier = state->value = lbl_91_rodata_30;
}
extern "C" float fn_91_10188(MarioScalarMultiplier* state) { return state->value; }
extern "C" void fn_91_10190(MarioScalarMultiplier* state, float value) { state->value = value; }
extern "C" float fn_91_10198(MarioScalarMultiplier* state) { return state->multiplier; }
extern "C" void fn_91_101A0(MarioScalarMultiplier* state, float multiplier) { state->multiplier = multiplier; }
extern "C" float fn_91_101A8(MarioScalarMultiplier* state) { return state->multiplier * state->value; }
