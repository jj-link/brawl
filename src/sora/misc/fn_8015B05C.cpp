#pragma force_active on
extern "C" void __register_global_object(void* obj, void (*dtor)(void*), void* handle);
extern "C" void fn_80158BEC(void* p);
extern unsigned int lbl_8049ED30[];
extern unsigned int lbl_8049ED20[];

extern "C" void fn_8015B05C(void)
{
    lbl_8049ED30[0] = 0;
    lbl_8049ED30[1] = 0;
    lbl_8049ED30[2] = 0;
    lbl_8049ED30[3] = 0;
    lbl_8049ED30[4] = 0;
    lbl_8049ED30[9] |= 0x80000000;
    __register_global_object(lbl_8049ED30, fn_80158BEC, lbl_8049ED20);
}

__declspec(section ".ctors") extern void* const fn_8015B05C_ctor = (void*)fn_8015B05C;
