#pragma force_active on
void operator delete(void*);
extern "C" void* fn_102_A538(void*, short);
extern "C" void* fn_102_A418(void*, short);

extern "C" void* fn_102_A598(void* object, short deleting) {
    if (object != 0) {
        fn_102_A538(static_cast<unsigned char*>(object) + 0x60, -1);
        fn_102_A418(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
