#pragma force_active on
extern "C" void fn_27_1A15B8(void*, short);
extern "C" void fn_109_5390(void*, short);

extern "C" void* fn_109_5318(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A15B8(storage + 0x1fc, -1);
        if (object != 0) {
            fn_109_5390(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
