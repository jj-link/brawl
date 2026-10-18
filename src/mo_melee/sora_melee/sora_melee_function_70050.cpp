#pragma force_active on
extern "C" {
extern void* lbl_27_bss_120[];
void* fn_80046958(void* a, void* b);
}

extern "C" void* fn_27_70050(void* p)
{
    return fn_80046958(lbl_27_bss_120[*(unsigned int*)p], ((void**)p)[1]);
}
