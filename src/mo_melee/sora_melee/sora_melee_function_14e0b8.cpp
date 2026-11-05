#pragma force_active on

extern "C" void* getConstantIndefinite__15soValueAccesserFP16soModuleAccesserUlUl(void* self, unsigned long a, unsigned long b);

struct S0 {
    char pad[0x48];
    void* acc;
};

struct S1 {
    void* ptr;
    unsigned int type;
};

extern "C" void fn_27_14E0B8(S0* arg0, S1* arg1) {
    if (arg1->type != 0) {
        if (arg1->type > 1) {
            float* p = (float*)getConstantIndefinite__15soValueAccesserFP16soModuleAccesserUlUl(arg0->acc, 0xA7FD, 0);
            float* q = (float*)arg1->ptr;
            q[13] = p[0];
            q[14] = p[1];
            q[15] = p[2];
            float* q2 = (float*)arg1->ptr;
            q2[22] = p[3];
            q2[23] = p[4];
        }
        if (arg1->type > 4) {
            float* p = (float*)getConstantIndefinite__15soValueAccesserFP16soModuleAccesserUlUl(arg0->acc, 0xA7FF, 0);
            float* q = (float*)arg1->ptr;
            q[37] = p[0];
            q[38] = p[1];
            q[39] = p[2];
        }
        if (arg1->type > 6) {
            float* p = (float*)getConstantIndefinite__15soValueAccesserFP16soModuleAccesserUlUl(arg0->acc, 0xA7FE, 0);
            float* q = (float*)arg1->ptr;
            q[52] = p[0];
            q[53] = p[1];
            q[54] = p[2];
            q[55] = p[3];
            float* q2 = (float*)arg1->ptr;
            q2[60] = p[4];
            q2[61] = p[5];
            q2[62] = p[6];
            q2[63] = p[7];
        }
    }
}