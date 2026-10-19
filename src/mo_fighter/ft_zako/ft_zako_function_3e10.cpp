#pragma force_active on
void operator delete(void*);
extern "C" void* fn_126_3E7C(void*, short);
extern "C" void* fn_126_3EDC(void*, short);

extern "C" void* fn_126_3E10(void* object, short deleting) {
    if (object != 0) {
        fn_126_3E7C(static_cast<unsigned char*>(object) + 0x24, -1);
        fn_126_3EDC(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
