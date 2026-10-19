#pragma force_active on
void operator delete(void*);
extern "C" void fn_126_1D68(void*, short);
extern "C" void fn_126_1DC4(void*, short);

extern "C" void* fn_126_3EDC(void* object, short deleting) {
    if (object != 0) {
        fn_126_1D68(static_cast<unsigned char*>(object) + 0x14, 0);
        fn_126_1DC4(static_cast<unsigned char*>(object) + 0x8, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
