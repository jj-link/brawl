#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_27_1A262C(void*, short);
void* fn_101_4324(void*, short);
void* fn_101_4364(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_101_429C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        if (members + 0x24 != 0) {
            fn_27_1A262C(members + 0x34, static_cast<short>(-1));
            fn_101_4324(members + 0x24, static_cast<short>(0));
        }
        fn_101_4364(object, static_cast<short>(-1));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
