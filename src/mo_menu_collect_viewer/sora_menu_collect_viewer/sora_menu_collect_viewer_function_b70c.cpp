#pragma force_active on
extern "C" int fn_800B61C0(void*);
extern "C" void fn_16_AF8(void*);

struct MenuCollectViewer {
    unsigned char pad_000[0x40];
    void* resource;
    unsigned char pad_044[0xE4];
    int state;
    unsigned char pad_12C[0x78];
    unsigned char member_1A4;
};

extern "C" int fn_6_B70C(MenuCollectViewer* self) {
    if (fn_800B61C0(self->resource)) {
        fn_16_AF8(&self->member_1A4);
        return 1;
    }
    return self->state;
}
