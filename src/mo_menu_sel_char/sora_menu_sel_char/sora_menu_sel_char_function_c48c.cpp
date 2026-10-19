#pragma force_active on
extern "C" {
extern const unsigned char lbl_10_rodata_40C[];
extern const unsigned char lbl_10_rodata_328[];

unsigned char fn_10_C48C(void* p, int id) {
    if (id == 9 || id == 13) {
        return lbl_10_rodata_40C[*(int*)((char*)p + 0x604)];
    }
    return (lbl_10_rodata_328 + id * 12)[5];
}
}
