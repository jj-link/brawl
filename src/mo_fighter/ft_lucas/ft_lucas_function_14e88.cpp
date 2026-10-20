#pragma force_active on
extern "C" {
void __dt__24soCollisionHitModuleImplFv(void*, short);
void fn_27_CC984(void*, short);
void fn_27_4CAA0(void*, short);
void fn_27_CC654(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_114_14E88(void* this_ptr, short param) {
    if (this_ptr) {
        short destroy = -1;
        __dt__24soCollisionHitModuleImplFv(static_cast<char*>(this_ptr) + 0x1a4, destroy);
        fn_27_CC984(static_cast<char*>(this_ptr) + 0x160, destroy);
        fn_27_4CAA0(static_cast<char*>(this_ptr) + 0xdc, destroy);
        fn_27_CC654(this_ptr, destroy);
        if (param > 0) {
            __dl__FPv(this_ptr);
        }
    }
    return this_ptr;
}
