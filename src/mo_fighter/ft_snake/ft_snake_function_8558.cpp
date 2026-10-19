#pragma force_active on
void operator delete(void*);
extern "C" void* fn_122_85C8(void*, short);
extern "C" void* fn_122_8880(void*, short);

extern "C" void* fn_122_8558(void* object, short deleting) {
    if (object != 0) {
        fn_122_85C8(static_cast<unsigned char*>(object) + 0x2DA8, -1);
        fn_122_8880(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
