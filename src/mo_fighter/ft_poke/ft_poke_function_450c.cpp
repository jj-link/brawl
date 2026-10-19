#pragma force_active on
void operator delete(void*);
extern "C" void* fn_116_457C(void*, short);
extern "C" void* fn_116_4D88(void*, short);

extern "C" void* fn_116_450C(void* object, short deleting) {
    if (object != 0) {
        fn_116_457C(static_cast<unsigned char*>(object) + 0x5B98, -1);
        fn_116_4D88(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
