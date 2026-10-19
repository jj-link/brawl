#pragma force_active on
void operator delete(void*);
extern "C" void* fn_115_BDD0(void* object, short deleting);
extern "C" void* fn_115_BCB0(void* object, short deleting);

extern "C" void* fn_115_BE30(void* object, short deleting) {
    if (object != 0) {
        fn_115_BDD0(static_cast<unsigned char*>(object) + 0x60, -1);
        fn_115_BCB0(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
