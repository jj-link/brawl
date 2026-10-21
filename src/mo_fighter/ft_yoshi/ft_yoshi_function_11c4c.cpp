#pragma force_active on
typedef unsigned int u32;

struct DestructorChain {
    DestructorChain* next;
    void* destructor;
    void* object;
};

extern "C" {
extern void* fn_95_11C0C(void*, int);
extern void fn_95_11C94(void*);
extern void* __register_global_object(void*, void*, DestructorChain*);
extern unsigned char lbl_95_bss_3DC[];
extern unsigned char lbl_95_bss_3D0[];

void fn_95_11C4C() {
    fn_95_11C94(lbl_95_bss_3DC);
    __register_global_object(lbl_95_bss_3DC,
                             (void*)fn_95_11C0C,
                             (DestructorChain*)lbl_95_bss_3D0);
}
}

__declspec(section ".ctors") extern void* const fn_95_11C4C_ctor = (void*)fn_95_11C4C;
