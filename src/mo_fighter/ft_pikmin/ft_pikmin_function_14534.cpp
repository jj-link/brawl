#pragma force_active on
void operator delete(void*);
extern "C" void* fn_113_145A4(void*, short);
extern "C" void* fn_113_148CC(void*, short);

extern "C" void* fn_113_14534(void* object, short deleting) {
    if (object != 0) {
        fn_113_145A4(static_cast<unsigned char*>(object) + 0x2990, -1);
        fn_113_148CC(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
