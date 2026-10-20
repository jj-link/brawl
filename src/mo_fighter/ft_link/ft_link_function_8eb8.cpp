#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_93_62F8(void* object, short flag);
void* fn_93_62B8(void* p, short flag);
void* fn_93_6394(void* object, short count);
void* fn_27_C7770(void*, short);
}

extern "C" void* fn_93_8EB8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* p = static_cast<unsigned char*>(object);
        short m1 = -1;
        fn_93_62F8(p + 0xdc, m1);
        fn_93_62B8(p + 0xc0, m1);
        fn_93_6394(p + 0x14, m1);
        if (object != 0) {
            fn_27_C7770(object, m1);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
