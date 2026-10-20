#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_94_2158(void*, short);
void* fn_94_21F4(void*, short);
void* fn_94_2234(void*, short);
void* fn_27_C7770(void*, short);
}

extern "C" void* fn_94_23E4(void* object, short deleting) {
    if (object != 0) {
        short minusOne = -1;
        fn_94_2158(static_cast<unsigned char*>(object) + 0xDC, minusOne);
        fn_94_21F4(static_cast<unsigned char*>(object) + 0xC0, minusOne);
        fn_94_2234(static_cast<unsigned char*>(object) + 0x14, minusOne);
        if (object != 0) {
            fn_27_C7770(object, minusOne);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
