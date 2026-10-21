#pragma force_active on
extern "C" {
struct YoshiUnknown4 { unsigned int data; };
struct DestructorChain;
YoshiUnknown4* fn_95_F3D4(void);
void fn_95_F784(void*, void*);
void fn_95_F698(void*);
extern unsigned char lbl_95_bss_384[12];
extern unsigned char lbl_95_bss_378[12];
void __register_global_object(void*, void*, DestructorChain*);
}
struct DestructorChain { DestructorChain* next; void* destructor; void* object; };
extern "C" void fn_95_F734(void) {
    void* arg = fn_95_F3D4();
    fn_95_F784(lbl_95_bss_384, arg);
    __register_global_object(lbl_95_bss_384, (void*)fn_95_F698, (DestructorChain*)lbl_95_bss_378);
}

__declspec(section ".ctors") extern void* const fn_95_F734_ctor = (void*)fn_95_F734;
