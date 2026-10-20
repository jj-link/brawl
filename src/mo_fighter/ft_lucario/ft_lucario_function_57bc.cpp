#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_D2904(void*, short);
extern "C" void* fn_118_5834(void*, short);

extern "C" void* fn_118_57BC(void* object, short deleting) {
    if (object != 0) {
        fn_27_D2904(static_cast<unsigned char*>(object) + 0x154, -1);
        if (object != 0) {
            fn_118_5834(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
