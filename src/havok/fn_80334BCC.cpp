extern "C" void fn_80334B4C();
extern "C" char lbl_80533708[16];
extern "C" void* lbl_805A0ED0;
extern "C" char lbl_805A0F40;

#pragma force_active on
extern "C" void fn_80334BCC() {
    char* blk = lbl_80533708;
    *(void(**)())(blk) = fn_80334B4C;
    *(void**)(blk + 8) = &lbl_805A0F40;
    *(void**)(blk + 4) = lbl_805A0ED0;
    lbl_805A0ED0 = blk;
}

__declspec(section ".ctors") extern void* const fn_80334BCC_ctor = (void*)fn_80334BCC;
