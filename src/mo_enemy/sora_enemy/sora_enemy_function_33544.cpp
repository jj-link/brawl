#pragma force_active on
extern "C" {
void fn_41_33544(char* param_1, float param_2);
void fn_41_33718(char* param_1, float param_2);
}

extern char lbl_41_rodata_E54[12];

void fn_41_33544(char* param_1, float param_2) {
    float* ptr = (float*)(param_1 + 0x21D4);
    float val = *ptr;
    float zero = *(float*)lbl_41_rodata_E54;
    if (val > zero) {
        *ptr = val - param_2;
        float fresh_val = *ptr;
        if (fresh_val <= zero) {
            fn_41_33718(param_1, param_2);
        }
    }
}
