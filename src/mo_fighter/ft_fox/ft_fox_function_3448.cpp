#pragma force_active on
void operator delete(void*);
extern "C" void fn_97_34A8(void*, short);

extern "C" void* fn_97_3448(void* object, short deleting) {
    if (object != 0) {
        fn_97_34A8(static_cast<unsigned char*>(object) + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
