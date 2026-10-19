#pragma force_active on
extern "C" {
void* fn_125_48BC(void*, short);
void* fn_125_4FFC(void*, short);
void __dl__FPv(void*);

#pragma dont_inline on
void* fn_125_484C(void* object, short deleting) {
    if (object != 0) {
        fn_125_48BC(static_cast<unsigned char*>(object) + 0x8608, static_cast<short>(-1));
        fn_125_4FFC(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
#pragma dont_inline reset
}
