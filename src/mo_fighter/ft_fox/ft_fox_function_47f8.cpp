#pragma force_active on
extern "C" {
void* fn_97_4868(void* object, short deleting);
void fn_97_50D4(void* object, short deleting);
void __dl__FPv(void* object);

#pragma dont_inline on
void* fn_97_47F8(void* object, short deleting) {
    if (object != 0) {
        fn_97_4868(static_cast<unsigned char*>(object) + 0x8608, static_cast<short>(-1));
        fn_97_50D4(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
#pragma dont_inline reset
}
