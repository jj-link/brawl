#pragma force_active on
extern "C" {
extern unsigned char __vt__10soNullable[];
extern unsigned char lbl_27_data_9048[];
extern unsigned char lbl_27_bss_170[];
extern unsigned char lbl_27_bss_160[];
extern void fn_27_7AAD0(void*, int);
extern void __register_global_object(void*, void*, void*);
}

extern "C" void fn_27_7B320()
{
    unsigned char* object = lbl_27_bss_170;
    unsigned char* initialVtable = __vt__10soNullable;
    unsigned char* data = lbl_27_data_9048;
    void (*destructor)(void*, int) = fn_27_7AAD0;
    unsigned char* chain = lbl_27_bss_160;

    *(unsigned char**)object = initialVtable;
    object[4] = 0;
    *(unsigned char**)object = data;
    __register_global_object(object, (void*)destructor, chain);
}

__declspec(section ".ctors") extern void* const fn_27_7B320_ctor = (void*)fn_27_7B320;
