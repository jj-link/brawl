#pragma force_active on

extern "C" {
struct MemberStorage {
    void* vtable;
};

struct DestructorChain;

extern unsigned char lbl_115_bss_304[];
extern unsigned char lbl_115_bss_2F8[];

void* fn_115_111C4(MemberStorage*);
void* fn_115_1113C(void*, short);
void* __register_global_object(
    void* object,
    void* (*destructor)(void*, short),
    DestructorChain* chain
);

void fn_115_1117C() {
    fn_115_111C4(reinterpret_cast<MemberStorage*>(lbl_115_bss_304));
    __register_global_object(
        lbl_115_bss_304,
        fn_115_1113C,
        reinterpret_cast<DestructorChain*>(lbl_115_bss_2F8)
    );
}
}

__declspec(section ".ctors") extern void* const fn_115_1117C_ctor = (void*)fn_115_1117C;
