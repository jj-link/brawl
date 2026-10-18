#pragma force_active on
void operator delete(void*);

extern "C" void fn_121_486C(void*, short);

extern "C" void* fn_121_12E1C(void* object, short deleting) {
    if (object != 0) {
        fn_121_486C(static_cast<unsigned char*>(object) + 0x14, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
