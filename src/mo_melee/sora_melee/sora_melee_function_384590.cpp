#pragma force_active on
typedef int s32;

extern "C" s32 fn_27_1454C0(const void* self);

extern "C" s32 fn_27_384590(const void* self, s32 unused, s32 column, s32 index) {
    return (*(s32* const*)((const char*)self - 0x176A0 + fn_27_1454C0(self) * 0x14 + column * 4))[index];
}
