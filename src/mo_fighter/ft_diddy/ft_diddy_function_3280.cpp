#pragma force_active on
extern "C" void* fn_115_32F0(void*, short);
extern "C" void* fn_115_46CC(void*, short);

extern "C" void* fn_115_3280(void* object, short deleting) {
    if (object != 0) {
        fn_115_32F0(static_cast<unsigned char*>(object) + 0x8, -1);
        fn_115_46CC(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
