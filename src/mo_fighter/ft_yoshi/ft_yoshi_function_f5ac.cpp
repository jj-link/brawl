#pragma force_active on
typedef void (*Destructor)(void*, int);

struct DestructorChain {
    DestructorChain* next;
    void* destructor;
    void* object;
};

struct FnObj {
    unsigned char data[12];
};

extern "C" FnObj* fn_95_F3D4(void);
extern "C" void fn_95_F5FC(FnObj*, void*);
extern "C" void fn_95_F510(void*, int);
extern "C" void* __register_global_object(void*, void*, DestructorChain*);

extern "C" {
extern FnObj lbl_95_bss_36C;
extern DestructorChain lbl_95_bss_360;
}

extern "C" void fn_95_F5AC(void) {
    FnObj* value = fn_95_F3D4();
    fn_95_F5FC(&lbl_95_bss_36C, value);
    __register_global_object(&lbl_95_bss_36C, (void*)fn_95_F510,
                             &lbl_95_bss_360);
}

__declspec(section ".ctors") extern void* const fn_95_F5AC_ctor = (void*)fn_95_F5AC;
