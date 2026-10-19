#pragma force_active on
void operator delete(void*);
extern "C" void fn_27_1A2524(void*, short);
extern "C" void* fn_109_3E98(void* ptr, short count);

extern "C" void* fn_109_5874(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A2524(static_cast<unsigned char*>(object) + 0x10, -1);
        fn_109_3E98(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
