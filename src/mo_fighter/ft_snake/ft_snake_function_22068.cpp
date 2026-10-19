#pragma force_active on
void operator delete(void*);
extern "C" void* fn_122_220D8(void*, short);
extern "C" void* fn_122_5A94(void*, short);

extern "C" void* fn_122_22068(void* object, short deleting) {
    if (object != 0) {
        fn_122_220D8(static_cast<unsigned char*>(object) + 0x8, -1);
        fn_122_5A94(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
