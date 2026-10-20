#pragma force_active on
extern "C" void fn_27_1A1E70(void*, short);
extern "C" void fn_112_5DB0(void*, short);

extern "C" void* fn_112_5D38(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A1E70(storage + 0x4B8, -1);
        if (object != 0) {
            fn_112_5DB0(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
