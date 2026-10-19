#pragma force_active on
void operator delete(void*);
extern "C" void* fn_109_32B0(void*, short);
extern "C" void fn_109_4A24(void*, short);

extern "C" void* fn_109_3240(void* object, short deleting) {
    if (object != 0) {
        fn_109_32B0(static_cast<unsigned char*>(object) + 0x8, -1);
        fn_109_4A24(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
