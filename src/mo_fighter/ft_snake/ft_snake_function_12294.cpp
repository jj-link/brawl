#pragma force_active on
void operator delete(void*);
extern "C" void* fn_122_12234(void*, short);
extern "C" void* fn_122_12114(void*, short);

extern "C" void* fn_122_12294(void* object, short deleting) {
    if (object != 0) {
        fn_122_12234(static_cast<unsigned char*>(object) + 0x60, -1);
        fn_122_12114(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
