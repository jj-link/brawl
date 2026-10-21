#pragma force_active on
typedef struct DestructorChain {
    void* next;
    void* destructor;
    void* object;
} DestructorChain;

extern "C" void* fn_121_15308(void*, short);
extern "C" void fn_121_15390(void*);
extern "C" void* __register_global_object(void*, void*, DestructorChain*);

extern "C" void fn_121_15348() {
    extern unsigned char lbl_121_bss_284[];
    extern unsigned char lbl_121_bss_278[];

    fn_121_15390(lbl_121_bss_284);
    __register_global_object(
        lbl_121_bss_284,
        (void*)fn_121_15308,
        (DestructorChain*)lbl_121_bss_278
    );
}

__declspec(section ".ctors") extern void* const fn_121_15348_ctor = (void*)fn_121_15348;
