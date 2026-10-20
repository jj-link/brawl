#pragma force_active on
extern "C" void operator delete(void*);
extern "C" void* fn_27_1A1E70(void*, short);
extern "C" void* fn_102_4C20(void*, short);

extern "C" void* fn_102_4BA8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A1E70(storage + 0x190, -1);
        if (object != 0) {
            fn_102_4C20(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
