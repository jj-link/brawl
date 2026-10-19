#pragma force_active on
extern "C" {
extern const unsigned char lbl_10_rodata_6B4[4];

int fn_10_14620(void* self, int flag) {
    int mode = flag ? 1 : *(int*)((char*)self + 0x1B4);
    switch (mode) {
    case 0:
        return 6;
    case 2:
        return 5;
    default:
        break;
    }
    void* p = *(void**)((char*)self + 0x1F4);
    if (*(unsigned char*)((char*)p + 0x5C8) != 0) {
        int idx = *(int*)((char*)self + 0x1C0);
        return (int)lbl_10_rodata_6B4[idx] + 1;
    }
    return *(int*)((char*)self + 0x1B0) + 1;
}
}
