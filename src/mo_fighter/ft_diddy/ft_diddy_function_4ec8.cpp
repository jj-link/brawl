#pragma force_active on
extern "C" void* fn_27_1A1FE4(void*, short);
extern "C" void fn_115_4F40(void*, short);

extern "C" void* fn_115_4EC8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A1FE4(storage + 0x244, -1);
        if (object != 0) {
            fn_115_4F40(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
