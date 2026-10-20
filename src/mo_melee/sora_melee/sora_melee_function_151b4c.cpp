#pragma force_active on
extern "C" const float lbl_27_rodata_1E64[];

struct Vec2 {
    float x, y;

    Vec2(float value) : x(value), y(value) {}
};

struct State {
    char padding[12];
    Vec2 position;
    char padding14[8];
    float value;
    int flag;
};

extern "C" void fn_27_151B4C(int, int, int, State* state) {
    state->flag = 0;
    state->value = lbl_27_rodata_1E64[0];
    state->position = Vec2(lbl_27_rodata_1E64[0]);
}
