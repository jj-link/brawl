#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_27_75E0C(void*, short);
void* fn_27_64930(void*, short);
void* fn_101_2138(void*, short);
}

extern "C" void* fn_101_4090(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        fn_27_75E0C(members + 0x4C, static_cast<short>(-1));
        if (members + 0x20 != 0) {
            fn_27_64930(members + 0x20, static_cast<short>(0));
        }
        fn_101_2138(members + 0x14, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
