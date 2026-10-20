#pragma force_active on
extern "C" void* fn_92_2204(void*, short);
extern "C" void* fn_92_22A0(void*, short);
extern "C" void* fn_92_22E0(void*, short);
extern "C" void* fn_27_C7770(void*, short);
void operator delete(void*);

extern "C" void* fn_92_2490(void* object, short deleting) {
    if (object != 0) {
        short m = -1;
        fn_92_2204(static_cast<unsigned char*>(object) + 0xdc, m);
        fn_92_22A0(static_cast<unsigned char*>(object) + 0xc0, m);
        fn_92_22E0(static_cast<unsigned char*>(object) + 0x14, m);
        if (object != 0) {
            fn_27_C7770(object, m);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
