#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A241C(void*, short);

extern "C" void* fn_120_12D60(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A241C(static_cast<unsigned char*>(object) + 0x10, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
