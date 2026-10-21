#pragma force_active on
extern "C" {
void __register_global_object(void* obj, void (*dtor)(void*), void* ctx);
void fn_802C0590(void* self);
void fn_802C05E8(void* self);
extern unsigned char lbl_805325BC[];
extern unsigned char lbl_805325B0[];
}

extern "C" void fn_802C0644() {
    fn_802C0590(lbl_805325BC);
    __register_global_object(lbl_805325BC, (void (*)(void*))fn_802C05E8, lbl_805325B0);
}

__declspec(section ".ctors") extern void* const fn_802C0644_ctor = (void*)fn_802C0644;
