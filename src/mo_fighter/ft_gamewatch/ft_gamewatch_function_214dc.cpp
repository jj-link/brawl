#pragma force_active on
void operator delete(void*);
extern "C" void* fn_107_2154C(void*, short);
extern "C" void* fn_107_21780(void*, short);

extern "C" void* fn_107_214DC(void* object, short deleting) {
    if (object != 0) {
        fn_107_2154C(static_cast<unsigned char*>(object) + 0x1990, -1);
        fn_107_21780(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
