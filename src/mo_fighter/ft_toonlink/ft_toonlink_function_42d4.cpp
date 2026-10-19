#pragma force_active on
void operator delete(void*);
extern "C" void fn_121_4224(void*, short);
extern "C" void fn_121_41B8(void*, short);

extern "C" void* fn_121_42D4(void* object, short deleting) {
    if (object != 0) {
        fn_121_4224((unsigned char*)object + 0x24, -1);
        fn_121_41B8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
