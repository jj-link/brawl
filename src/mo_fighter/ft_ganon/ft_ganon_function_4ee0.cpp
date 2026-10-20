#pragma force_active on
extern "C" void fn_27_1A1E70(void*, short);
extern "C" void fn_109_4F58(void*, short);

extern "C" void* fn_109_4EE0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A1E70(storage + 0x4B8, -1);
        if (object != 0) {
            fn_109_4F58(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
