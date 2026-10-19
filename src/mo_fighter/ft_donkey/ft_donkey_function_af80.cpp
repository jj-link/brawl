#pragma force_active on
void operator delete(void*);
extern "C" void* fn_92_AF20(void*, short);
extern "C" void* fn_92_AE00(void*, short);

extern "C" void* fn_92_AF80(void* object, short deleting) {
    if (object != 0) {
        fn_92_AF20(static_cast<unsigned char*>(object) + 0x60, -1);
        fn_92_AE00(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
