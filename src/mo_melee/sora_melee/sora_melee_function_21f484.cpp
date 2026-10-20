#pragma force_active on
extern float lbl_27_rodata_32D0;
extern float lbl_27_rodata_32E4;

extern "C" float fn_27_21F484(void* a, void* b, void* c)
{
    return *(float*)((char*)a + 0x24) *
           (lbl_27_rodata_32D0 +
            lbl_27_rodata_32E4 * *(float*)((char*)b + 0x68));
}
