#pragma force_active on
extern "C" {
void* fn_27_614C4(void*, short);
void* fn_27_D3080(void*, short);

#pragma dont_inline on
void* fn_91_3878(void* object, short deleting) {
    if (object != 0) {
        fn_27_614C4(static_cast<unsigned char*>(object) + 0xac, static_cast<short>(-1));
        if (object != 0) fn_27_D3080(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
#pragma dont_inline reset
}
