#pragma force_active on
void operator delete(void*);
extern "C" void* fn_116_1D5A0(void* self, short flag);
extern "C" void* fn_116_53D8(void* ptr, short count);

extern "C" void* fn_116_1D530(void* object, short deleting) {
    if (object != 0) {
        fn_116_1D5A0(static_cast<unsigned char*>(object) + 0x8, -1);
        fn_116_53D8(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
