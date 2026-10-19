#pragma force_active on
extern "C" bool fn_41_1AE7C(void* p);
extern float lbl_41_rodata_C9C;

extern "C" float fn_41_1F130(void* p) {
    float f;
    if (fn_41_1AE7C(p) == 1) {
        f = lbl_41_rodata_C9C;
    } else {
        int kind = *(int*)((char*)p + 0x8);
        if (kind == 0x15) {
            goto load;
        }
        if (kind != 0x16) {
            goto def;
        }
load:
        f = *(float*)((char*)p + 0x78);
        return f;
def:
        f = lbl_41_rodata_C9C;
    }
    return f;
}
