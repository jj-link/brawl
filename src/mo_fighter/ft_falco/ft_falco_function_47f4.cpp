#pragma force_active on
extern "C" {
void* fn_108_4864(void* object, short deleting);
void* fn_108_4FA4(void* object, short deleting);

#pragma dont_inline on
void* fn_108_47F4(void* object, short deleting) {
    if (object != 0) {
        fn_108_4864(static_cast<unsigned char*>(object) + 0x85F8, static_cast<short>(-1));
        fn_108_4FA4(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
#pragma dont_inline reset
}
