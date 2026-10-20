#pragma force_active on
extern "C" void* fn_27_148B94()
{
    extern void* lbl_27_bss_3210[];

    void* object = lbl_27_bss_3210[0x12C / sizeof(void*)];
    return static_cast<void**>(object)[0xA8 / sizeof(void*)];
}
