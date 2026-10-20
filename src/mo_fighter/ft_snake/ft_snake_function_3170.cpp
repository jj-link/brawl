#pragma force_active on
extern "C" {
void* fn_27_93100(void*, short);
void* fn_122_31F8(void*, short);
void* fn_27_19F7F4(void*, short);
void* fn_27_1A57B8(void*, short);
void __dl__FPv(void*);

#pragma dont_inline on
void* fn_122_3170(void* object, short deleting) {
    if (object != 0) {
        fn_27_93100(static_cast<unsigned char*>(object) + 0x249a8, static_cast<short>(-1));
        fn_122_31F8(static_cast<unsigned char*>(object) + 0xa4, static_cast<short>(-1));
        fn_27_19F7F4(static_cast<unsigned char*>(object) + 0x28, static_cast<short>(-1));
        fn_27_1A57B8(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
#pragma dont_inline reset
}
