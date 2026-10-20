#pragma force_active on
extern "C" void* fn_27_1A1B88(void*, short);
extern "C" void fn_123_5564(void*, short);

extern "C" void* fn_123_54EC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A1B88(storage + 0x48c, -1);
        if (object != 0) {
            fn_123_5564(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
