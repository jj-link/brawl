#pragma force_active on
extern "C" {
extern void* lbl_8059FF90;
void* fn_800122E8(void* p, int id, int idx);

bool fn_27_A7B98(void*, int a, float* out) {
    void* p = fn_800122E8(lbl_8059FF90, 0x1c, a);
    if (p) {
        *out = *(float*)((char*)p + 0x38);
        return true;
    }
    return false;
}
}
