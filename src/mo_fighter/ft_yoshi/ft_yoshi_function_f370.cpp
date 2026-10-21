#pragma force_active on
typedef void (*Destructor)(void*, short);

struct DestructorChain {
    DestructorChain* next;
    Destructor destructor;
    void* object;
};

struct YoshiUnknown4;

extern "C" YoshiUnknown4* fn_95_F3D4(void);
extern "C" void fn_95_F3C0(void* self, void* arg);
extern "C" void* fn_95_F31C(void* ptr, short release);
extern "C" void* __register_global_object(
    void* object, void* destructor, DestructorChain* chain);

extern "C" unsigned char lbl_95_bss_354[12];
extern "C" DestructorChain lbl_95_bss_348;

extern "C" void fn_95_F370(void) {
    void* arg = fn_95_F3D4();
    fn_95_F3C0(lbl_95_bss_354, arg);
    __register_global_object(
        lbl_95_bss_354,
        reinterpret_cast<void*>(fn_95_F31C),
        &lbl_95_bss_348);
}

__declspec(section ".ctors") extern void* const fn_95_F370_ctor = (void*)fn_95_F370;
