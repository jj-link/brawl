#pragma force_active on
extern "C" void fn_801EC158(void*);
extern const float lbl_805A3360;
extern const float lbl_805A3368;

extern "C" void fn_801A7FC8(void** arg0, void* arg1) {
    if (arg1) {
        char* src = (char*)*arg0;
        if (src) {
            float* out = (float*)arg1;
            fn_801EC158(arg1);
            out[0] = *(float*)(src + 0xCC);
            out[3] = *(float*)(src + 0xD4);
            out[5] = -*(float*)(src + 0xD0);
            out[7] = *(float*)(src + 0xD8);
            out[10] = lbl_805A3360;
            out[11] = lbl_805A3368;
        }
    }
}
