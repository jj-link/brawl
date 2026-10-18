#pragma force_active on
void operator delete(void*);
extern "C" void fn_122_3E48(void*, short);
extern "C" void* fn_122_24340(void* object, short deleting) {
    if (object != 0) {
        fn_122_3E48(static_cast<unsigned char*>(object) + 0x28, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
