#pragma force_active on
extern "C" {
extern const float lbl_31_rodata_34;
extern const float lbl_31_rodata_40;
void setFrameNode__8MuObjectFf(void*, float);
void setUpdateRate__16gfModelAnimationFf(void*, float);
}
struct GG { char pad[0x30]; int* p; };
extern GG* g_GameGlobal;

extern "C" int fn_31_2C30(unsigned char* self) {
    int* e = g_GameGlobal->p;
    setFrameNode__8MuObjectFf(*(void**)(self + 0x1c4), (float)*(int*)(self + 0x4ac));
    for (int i = 0; i < 0x22; i++, e += 5) {
        if (e[0] != 1 && e[1] != 0) {
            int idx;
            switch (e[1]) {
            case 1: idx = i + 5; break;
            case 2: idx = i + 0x27; break;
            case 3: idx = i + 0x49; break;
            case 4: idx = i + 0x6b; break;
            default: idx = i + 5; break;
            }
            if (self[0x59]) setUpdateRate__16gfModelAnimationFf(*(void**)(*(char**)(self + 0x1c4 + idx * 4) + 0x14), lbl_31_rodata_40);
            else setUpdateRate__16gfModelAnimationFf(*(void**)(*(char**)(self + 0x1c4 + idx * 4) + 0x14), lbl_31_rodata_34);
        }
    }
    if (self[0x5e6]) setUpdateRate__16gfModelAnimationFf(*(void**)(*(char**)(self + 0x3f8) + 0x14), lbl_31_rodata_34);
    else setUpdateRate__16gfModelAnimationFf(*(void**)(*(char**)(self + 0x3f8) + 0x14), lbl_31_rodata_40);
    return *(int*)(self + 0x4a4);
}