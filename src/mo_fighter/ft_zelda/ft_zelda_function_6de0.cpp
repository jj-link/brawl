#pragma force_active on
void operator delete(void*);
extern "C" void fn_27_4B53C(void*, short);
extern "C" void fn_27_19C45C(void*, short);

// Destroy the embedded member, then the base; free storage when requested.
extern "C" void* fn_104_6DE0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short destroy = -1;
        fn_27_4B53C(storage + 0x17C, destroy);
        fn_27_19C45C(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
