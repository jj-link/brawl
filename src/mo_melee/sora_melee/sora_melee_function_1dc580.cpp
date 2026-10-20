#pragma force_active on
extern const float lbl_27_rodata_27E0;

extern "C" unsigned long long fn_27_1DC580(const void* self)
{
    union {
        struct {
            float x, y;
        } f;
        unsigned long long bits;
    } result;

    result.f.y = *(const float*)((const char*)self + 8);
    result.f.x = lbl_27_rodata_27E0;
    return result.bits;
}
