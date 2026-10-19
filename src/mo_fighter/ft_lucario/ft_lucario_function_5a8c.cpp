#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A1E70(void*, short);
extern "C" void* fn_118_5AFC(void*, short);

extern "C" void* fn_118_5A8C(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1E70(static_cast<unsigned char*>(object) + 0x1C, -1);
        fn_118_5AFC(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
