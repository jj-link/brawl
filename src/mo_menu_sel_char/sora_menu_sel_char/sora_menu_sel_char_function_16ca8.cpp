#pragma force_active on
extern "C" {
extern const unsigned char lbl_10_rodata_6B4[4];
int fn_800B5854(void*, int, int, int, int);

int fn_10_16CA8(void* self, int flag, int index) {
    return fn_800B5854(
        *(void**)((char*)self + 0xCC),
        flag ? lbl_10_rodata_6B4[index] : *(int*)((char*)self + 0x1B0),
        0x10, 0, 0);
}
}
