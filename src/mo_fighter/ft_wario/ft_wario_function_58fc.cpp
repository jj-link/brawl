#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_D2904(void* member, short deleteFlag);
extern "C" void fn_110_5974(void* object, short deleteFlag);

extern "C" void* fn_110_58FC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_D2904(storage + 0x154, -1);
        if (object != 0) {
            fn_110_5974(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
