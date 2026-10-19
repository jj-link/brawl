#pragma force_active on
void operator delete(void*);

extern "C" void* fn_126_7D3C(void*, short);
extern "C" void* fn_126_7C1C(void*, short);

extern "C" void* fn_126_7D9C(void* object, short deleting) {
    if (object != 0) {
        fn_126_7D3C(static_cast<unsigned char*>(object) + 0x60, -1);
        fn_126_7C1C(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
