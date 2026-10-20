#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_D2904(void* member, short deleteFlag);
extern "C" void fn_123_5A14(void* object, short flag);

extern "C" void* fn_123_599C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_D2904(storage + 0x154, -1);
        if (object != 0) {
            fn_123_5A14(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
