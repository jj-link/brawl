#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_102_212C(void*, short);
void* fn_102_21C8(void*, short);
void* fn_102_2208(void*, short);
void* fn_27_C7770(void*, short);
}

extern "C" void* fn_102_1A220(void* object, short deleting) {
    if (object != 0) {
        fn_102_212C(static_cast<unsigned char*>(object) + 0xDC, -1);
        fn_102_21C8(static_cast<unsigned char*>(object) + 0xC0, -1);
        fn_102_2208(static_cast<unsigned char*>(object) + 0x14, -1);
        if (object != 0) {
            fn_27_C7770(object, -1);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
