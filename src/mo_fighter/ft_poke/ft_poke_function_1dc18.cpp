#pragma force_active on
void operator delete(void*);
extern "C" void* fn_116_1DC88(void*, short);
extern "C" void* fn_116_1E1B8(void*, short);

extern "C" void* fn_116_1DC18(void* object, short deleting) {
    if (object != 0) {
        fn_116_1DC88(static_cast<unsigned char*>(object) + 0x1F8C, -1);
        fn_116_1E1B8(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
