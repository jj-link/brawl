#pragma force_active on
void operator delete(void*);
extern "C" void fn_27_1A2524(void*, short);
extern "C" void* fn_115_3C4C(void* ptr, short flag);

extern "C" void* fn_115_5514(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A2524(static_cast<unsigned char*>(object) + 0x10, -1);
        fn_115_3C4C(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
