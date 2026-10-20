#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_93_62F8(void*, short);
void* fn_93_62B8(void*, short);
void* fn_93_6394(void*, short);
void* fn_27_C7770(void*, short);
}

extern "C" void* fn_93_8F44(void* object, short deleting) {
    if (object != 0) {
        short minusOne = -1;
        fn_93_62F8(static_cast<char*>(object) + 0xDC, minusOne);
        fn_93_62B8(static_cast<char*>(object) + 0xC0, minusOne);
        fn_93_6394(static_cast<char*>(object) + 0x14, minusOne);
        if (object != 0) {
            fn_27_C7770(object, minusOne);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
