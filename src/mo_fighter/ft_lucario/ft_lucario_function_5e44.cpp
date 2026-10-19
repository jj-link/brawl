#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_6A3D8(void*, short);
extern "C" void* fn_27_199E3C(void*, short);

extern "C" void* fn_118_5E44(void* object, short deleting) {
    if (object != 0) {
        fn_27_6A3D8(static_cast<unsigned char*>(object) + 0x144, -1);
        fn_27_199E3C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
