#pragma force_active on
extern "C" float fn_27_194EE0(void*);

extern const float lbl_27_rodata_1E60;
extern const float lbl_27_rodata_1E7C;

struct State {
    unsigned char padding[0x38];
    unsigned int : 26;
    unsigned int flag : 1;
    unsigned int : 5;
};

#pragma fp_contract off

extern "C" float fn_27_152180(void*, void* arg, State* state) {
    float value = fn_27_194EE0(arg);
    if (state->flag) {
        value *= (lbl_27_rodata_1E60 -
                  lbl_27_rodata_1E7C * (lbl_27_rodata_1E60 - value)) / value;
    }
    return value;
}
