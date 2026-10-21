#pragma force_active on
// ABI views for the embedded resource handles and module accesser.
struct PikachuResourceHandle {
    void* vtable;
    unsigned char state[0x10];
};
struct PikachuTaggedResourceHandle {
    PikachuResourceHandle handle;
    int index;
};
struct PikachuAccesser {
    unsigned char prefix[8];
    void* stageObject;
};
struct PikachuFighter {
    unsigned char prefix[0x10C];
    void* resource;
};
extern "C" {
extern const char lbl_98_data_26D4[], lbl_98_data_2F88[];
extern const char lbl_27_data_2AB90[], lbl_27_bss_A48[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_27_14033C(PikachuResourceHandle*, void*);
void* fn_27_B5048(void*, PikachuResourceHandle*, PikachuResourceHandle*,
                  PikachuTaggedResourceHandle*, PikachuAccesser*, const void*);
}

extern "C" void* fn_98_7388(unsigned char* self, int, PikachuAccesser* accesser) {
    short one = 1;
    void* res = static_cast<PikachuFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_98_data_26D4, lbl_98_data_2F88, one))->resource;
    fn_27_14033C(reinterpret_cast<PikachuResourceHandle*>(self + 4), res);
    res = static_cast<PikachuFighter*>(
        __dynamic_cast(accesser->stageObject, 0x3C,
                       lbl_98_data_26D4, lbl_98_data_2F88, one))->resource;
    PikachuTaggedResourceHandle* secondary =
        reinterpret_cast<PikachuTaggedResourceHandle*>(self + 0x18);
    fn_27_14033C(&secondary->handle, res);
    secondary->handle.vtable = const_cast<char*>(lbl_27_data_2AB90);
    secondary->index = -1;
    fn_27_B5048(self + 0x30, reinterpret_cast<PikachuResourceHandle*>(self + 4),
                reinterpret_cast<PikachuResourceHandle*>(self + 4),
                secondary, accesser, lbl_27_bss_A48);
    return self;
}
