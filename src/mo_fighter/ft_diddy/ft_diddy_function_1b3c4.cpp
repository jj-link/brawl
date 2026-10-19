#pragma force_active on
void operator delete(void*);
extern "C" void* fn_115_1B334(void*, short);
extern "C" void* fn_115_1AF84(void*, short);

extern "C" void* fn_115_1B3C4(void* object, short deleting) {
    if (object != 0) {
        fn_115_1B334(static_cast<unsigned char*>(object) + 0x189C, -1);
        fn_115_1AF84(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
