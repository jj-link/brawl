#pragma force_active on
extern "C" void fn_40_2BB30();

extern "C" void fn_40_2BED4(void* self, float delta)
{
    float current = *(float*)((char*)self + 0x178);
    extern const float lbl_40_rodata_468[];
    if (!(current > lbl_40_rodata_468[0]))
        return;

    float limit = *(float*)((char*)self + 0x17C);
    if (current > limit) {
        *(float*)((char*)self + 0x17C) = limit + delta;
        return;
    }

    fn_40_2BB30();
}
