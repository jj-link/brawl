#pragma force_active on
extern "C" void* fn_802E98C4(void);
extern "C" void fn_802E9890(void* arg0);
extern "C" void fn_802E98B0(void* self);
extern "C" char lbl_804132C8[];

struct Foo {
    char* a;
    void (*b)(void*);
    void (*c)(void*);
    void* d;
};

extern "C" Foo lbl_805331C8;

extern "C" void fn_802E9B40(void) {
    void* temp_r3 = fn_802E98C4();
    lbl_805331C8.a = lbl_804132C8;
    lbl_805331C8.b = fn_802E9890;
    lbl_805331C8.c = fn_802E98B0;
    lbl_805331C8.d = temp_r3;
}

__declspec(section ".ctors") extern void* const fn_802E9B40_ctor = (void*)fn_802E9B40;
