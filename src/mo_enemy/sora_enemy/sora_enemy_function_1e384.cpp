#pragma force_active on
typedef unsigned long long u64;

extern "C" const float lbl_41_rodata_C9C;

struct Unk {
    char pad0[0x8];
    int unk8;
    char padC[0x48 - 0xC];
    unsigned char unk48;
    char pad49[0xb4 - 0x49];
    unsigned int unkB4;
    unsigned int unkB8;
};

union Pair {
    struct {
        float x;
        float y;
    } f;
    u64 bits;
};

extern "C" bool fn_41_1AE7C(Unk* p);
extern "C" bool fn_41_1C9C4(Unk* p);
extern "C" int fn_41_1AE30(int p);

extern "C" u64 fn_41_1E384(Unk* self) {
    if (fn_41_1AE7C(self) == 1) {
        Pair value;
        value.f.x = lbl_41_rodata_C9C;
        value.f.y = lbl_41_rodata_C9C;
        return value.bits;
    }
    if (fn_41_1C9C4(self) == 1) {
        Pair value;
        value.f.x = lbl_41_rodata_C9C;
        value.f.y = lbl_41_rodata_C9C;
        return value.bits;
    }
    if (self->unk48 == 1) {
        Pair value;
        value.f.x = lbl_41_rodata_C9C;
        value.f.y = lbl_41_rodata_C9C;
        return value.bits;
    }
    if (fn_41_1AE30(self->unk8) == 0) {
        return *(u64*)((char*)self + 0xB4);
    }
    Pair value;
    value.f.x = lbl_41_rodata_C9C;
    value.f.y = lbl_41_rodata_C9C;
    return value.bits;
}
