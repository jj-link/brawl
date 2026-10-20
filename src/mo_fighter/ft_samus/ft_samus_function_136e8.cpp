#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_94_2158(void*, short);
void* fn_94_21F4(void*, short);
void* fn_94_2234(void*, short);
void* fn_27_C7770(void*, short);
}

extern "C" void* fn_94_136E8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short minusOne = -1;
        fn_94_2158(members + 0xdc, minusOne);
        fn_94_21F4(members + 0xc0, minusOne);
        fn_94_2234(members + 0x14, minusOne);
        if (object != 0) {
            fn_27_C7770(object, minusOne);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
