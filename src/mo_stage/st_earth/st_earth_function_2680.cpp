#pragma force_active on
extern "C" float randf__Fv();
extern "C" void setIdentity__6MatrixFv(void*);
extern "C" const float lbl_66_rodata_0[];

extern "C" void fn_66_2680(void* arg0, void* arg1) {
    const float* c = lbl_66_rodata_0;

    if (arg1 != 0) {
        void* inner = *(void**)((char*)arg0 + 0x9C);
        if (inner != 0) {
            char* out = (char*)arg1;
            float zero = c[0];

            out[0] = 0;
            *(float*)(out + 4) = zero;
            out[8] = 0;
            out[9] = 4;
            out[10] = 3;
            out[11] = 0;
            *(float*)(out + 12) = *(float*)((char*)inner + 0x34);
            *(float*)(out + 16) = *(float*)((char*)inner + 0x30);
            *(float*)(out + 20) = zero;
            *(float*)(out + 24) = zero;
            *(float*)(out + 28) = zero;

            *(float*)(out + 32) = c[0x64 / 4] + c[0x68 / 4] * randf__Fv();
            *(float*)(out + 36) = c[0x2C / 4];
            setIdentity__6MatrixFv(out + 40);
        }
    }
}
