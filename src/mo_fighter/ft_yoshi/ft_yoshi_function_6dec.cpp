#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A1E70(void*, short);
extern "C" void* fn_95_6E5C(void* object, short deleting);

extern "C" void* fn_95_6DEC(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1E70(static_cast<unsigned char*>(object) + 0x1C, static_cast<short>(-1));
        fn_95_6E5C(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
