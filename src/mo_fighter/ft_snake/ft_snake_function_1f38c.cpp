#pragma force_active on
void operator delete(void*);
extern "C" void* fn_122_1F3FC(void*, short);
extern "C" void* fn_122_1F518(void*, short);

extern "C" void* fn_122_1F38C(void* object, short deleting) {
    if (object != 0) {
        fn_122_1F3FC(static_cast<unsigned char*>(object) + 0x2104, -1);
        fn_122_1F518(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
