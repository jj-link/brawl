#pragma force_active on
extern "C" {
typedef struct DestructorChain {
    struct DestructorChain* next;
    void* destructor;
    void* object;
} DestructorChain;

void* __register_global_object(void* object, void* destructor, DestructorChain* chain);
void fn_104_F9FC(void* self);
void* fn_104_F974(void* p, short n);

extern int lbl_104_bss_1E4;
extern DestructorChain lbl_104_bss_1D8;

void fn_104_F9B4(void) {
    fn_104_F9FC(&lbl_104_bss_1E4);
    __register_global_object(&lbl_104_bss_1E4, (void*)fn_104_F974, &lbl_104_bss_1D8);
}
}

__declspec(section ".ctors") extern void* const fn_104_F9B4_ctor = (void*)fn_104_F9B4;
