#pragma force_active on
void operator delete(void*);
extern "C" void* fn_122_32C4(void*, short);
extern "C" void* fn_122_5A94(void*, short);

extern "C" void* fn_122_3254(void* object, short deleting) {
    if (object != 0) {
        fn_122_32C4(static_cast<unsigned char*>(object) + 8, -1);
        fn_122_5A94(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
