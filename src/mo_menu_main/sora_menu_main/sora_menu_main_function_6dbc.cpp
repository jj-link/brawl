#pragma force_active on

struct gfPadStatus {
    unsigned char data[0x38];
    signed char flag;
    int type;
};

extern "C" {
extern const float lbl_2_rodata_138[];
extern char lbl_2_data_D30[];
extern char lbl_2_data_D44[];
extern char lbl_2_data_D90[];
extern char lbl_2_data_718[];
extern void* g_gfPadSystem;

void fn_1_6ACC(void* a, int b);
void changeAnimN__8MuObjectFPCc(void* self, const char* name);
void setUpdateRate__16gfModelAnimationFf(void* self, float f);
void fn_2_678C(void* a, int b, int c, float* d, float* e, void* f, int g);
void fn_800A97AC(float f);
void* fn_800B6E08(void* a, float* b);
void* getInstance__16CameraControllerFv(void);
void* __dynamic_cast(void* a, int b, void* c, void* d, int e);
void fn_1_6AE0(void* a, int b);
void getSysPadStatus__11gfPadSystemFiP11gfPadStatus(void* self, int idx, gfPadStatus* st);
void OSReport(const char* fmt, ...);
void* fn_800B7AA4(void* a, int b);
}

#define OBJ (*(char**)(self + 0x40))

extern "C" void* fn_2_6DBC(char* self) {
    const float* c = lbl_2_rodata_138;
    gfPadStatus st;
    float local[3];
    float spC;
    float sp8;
    float k;
    void* ret;
    float f;

    fn_1_6ACC(*(void**)OBJ, *(int*)(*(char**)(OBJ + 0x156c) + 0x10));
    fn_1_6ACC(*(void**)OBJ, *(int*)(*(char**)(OBJ + 0x114) + 0x10));
    changeAnimN__8MuObjectFPCc(*(void**)(OBJ + 0x114), lbl_2_data_D30);
    setUpdateRate__16gfModelAnimationFf(*(void**)(*(char**)(OBJ + 0x114) + 0x14), c[22]);
    fn_1_6ACC(*(void**)OBJ, *(int*)(OBJ + 0x1578));
    fn_1_6ACC(*(void**)OBJ, *(int*)(OBJ + 0x157c));
    fn_2_678C(self, *(int*)(OBJ + 0x162c), *(int*)(self + 0x6f8), &spC, &sp8, self + 0x1e0, *(int*)(self + 0x6f4));
    k = c[23];
    local[1] = c[22];
    local[2] = (k + sp8) / k;
    local[0] = (k + spC) / k;
    OSReport(lbl_2_data_D44, local[0], local[1], local[2], k);
    fn_800B6E08(*(void**)(OBJ + 0x156c), local);
    __dynamic_cast(*(void**)((char*)getInstance__16CameraControllerFv() + 0x48), 4, lbl_2_data_D90, lbl_2_data_718, 0);
    fn_800A97AC(spC);
    fn_1_6AE0(*(void**)OBJ, *(int*)(*(char**)(OBJ + 0x118) + 0x10));
    getSysPadStatus__11gfPadSystemFiP11gfPadStatus(g_gfPadSystem, *(int*)(self + 0x6fc), &st);

    ret = *(void**)(OBJ + 0x118);
    if (st.flag != 0) {
        f = c[24];
    } else {
        switch (st.type) {
        case 0: f = c[21]; break;
        case 1: f = c[25]; break;
        case 2: f = c[26]; break;
        case 3: f = c[22]; break;
        default: f = c[21]; break;
        }
    }
    if (f >= c[21]) {
        ret = fn_800B7AA4(ret, 4);
    }
    return ret;
}
