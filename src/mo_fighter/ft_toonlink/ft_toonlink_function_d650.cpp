#pragma force_active on
void operator delete(void*);
extern "C" void fn_121_D5F0(void*, short);

extern "C" void* fn_121_D650(void* object, short deleting) {
    if (object != 0) {
        fn_121_D5F0(static_cast<unsigned char*>(object) + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
