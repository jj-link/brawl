#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_D2904(void* member, short deleteFlag);
extern "C" void fn_120_4750(void* object, short deleting);

extern "C" void* fn_120_46D8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_D2904(storage + 0xB4, -1);
        if (object != 0) {
            fn_120_4750(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
