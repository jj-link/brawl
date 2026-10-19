#pragma force_active on
extern "C" void* fn_27_1A1E70(void*, short);
extern "C" void* fn_116_60FC(void*, short);

void operator delete(void*);

extern "C" void* fn_116_608C(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1E70(static_cast<unsigned char*>(object) + 0x1C, -1);
        fn_116_60FC(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
