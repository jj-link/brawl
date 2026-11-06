#pragma force_active on

struct gfPadStatus {
    unsigned char data[0x38];
    signed char flag;
    int type;
};

extern "C" {
extern const float lbl_5_rodata_2F8[];
extern void* g_gfPadSystem;

void getSysPadStatus__11gfPadSystemFiP11gfPadStatus(void* self, int idx, gfPadStatus* st);
void fn_800B7AA4(void* a, int b);
}

extern "C" void fn_5_13D64(char* self) {
    const float* c = lbl_5_rodata_2F8;
    gfPadStatus st;
    float f;
    void* obj;

    getSysPadStatus__11gfPadSystemFiP11gfPadStatus(g_gfPadSystem, *(int*)(*(char**)(self + 0x1ac) + 0x1d68), &st);
    obj = *(void**)(*(char**)(self + 0x1ac) + 0x178);
    if (st.flag != 0) {
        f = c[10];
    } else {
        switch (st.type) {
        case 0: f = c[2]; break;
        case 1: f = c[11]; break;
        case 2: f = c[12]; break;
        case 3: f = c[13]; break;
        default: f = c[14]; break;
        }
    }
    if (f >= c[2]) {
        fn_800B7AA4(obj, 4);
    }
}
