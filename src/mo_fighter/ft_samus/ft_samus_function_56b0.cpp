#pragma force_active on
extern "C" void* fn_27_1A15B8(void*, short);
extern "C" void fn_94_5728(void*, short);

extern "C" void* fn_94_56B0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A15B8(storage + 0x1fc, -1);
        if (object != 0) {
            fn_94_5728(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
