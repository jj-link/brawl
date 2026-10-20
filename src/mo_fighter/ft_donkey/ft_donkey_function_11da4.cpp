#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_92_2204(void*, short);
void* fn_92_22A0(void*, short);
void* fn_92_22E0(void*, short);
void* fn_27_C7770(void*, short);
}

extern "C" void* fn_92_11DA4(void* object, short deleting) {
    if (object != 0) {
        short d = -1;
        fn_92_2204(static_cast<char*>(object) + 0xDC, d);
        fn_92_22A0(static_cast<char*>(object) + 0xC0, d);
        fn_92_22E0(static_cast<char*>(object) + 0x14, d);
        if (object != 0) {
            fn_27_C7770(object, d);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
