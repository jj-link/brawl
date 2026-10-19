#pragma force_active on
void operator delete(void*);
extern "C" void* fn_117_384C(void*, short);
extern "C" void* fn_117_3A50(void*, short);

extern "C" void* fn_117_37D8(void* object, short deleting) {
    if (object != 0) {
        fn_117_384C(static_cast<unsigned char*>(object) + 0x2F3E0, -1);
        fn_117_3A50(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
