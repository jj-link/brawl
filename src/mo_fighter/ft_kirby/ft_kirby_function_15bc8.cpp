#pragma force_active on
extern "C" unsigned char lbl_96_data_B370[];

extern "C" void* fn_96_15BC8(void* object)
{
    *(void**)object = (void*)(lbl_96_data_B370 + (lbl_96_data_B370 != (void*)0 ? 0 : 0));
    return object;
}
