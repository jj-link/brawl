#pragma force_active on
typedef struct DestructorChain
{
    struct DestructorChain* next;
    void* destructor;
    void* object;
} DestructorChain;

extern "C" void fn_27_16AD18(void*);
extern "C" void* fn_27_17FE88(void*, int);
extern "C" void* __register_global_object(void*, void*, DestructorChain*);

extern "C" unsigned char lbl_27_bss_4BFC[];
extern "C" unsigned char lbl_27_data_30648[];
extern "C" unsigned char lbl_27_bss_4BF0[];

extern "C" void fn_27_17FEC8()
{
    fn_27_16AD18(lbl_27_bss_4BFC);
    *(void**)lbl_27_bss_4BFC = lbl_27_data_30648;
    __register_global_object(
        lbl_27_bss_4BFC,
        (void*)fn_27_17FE88,
        (DestructorChain*)lbl_27_bss_4BF0
    );
}

__declspec(section ".ctors") extern void* const fn_27_17FEC8_ctor = (void*)fn_27_17FEC8;
