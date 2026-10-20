#pragma force_active on
void operator delete(void*);
extern "C" void* fn_92_9EB8(void*, short);
extern "C" void* fn_92_509C(void*, short);
extern "C" void* fn_92_510C(void*, short);

extern "C" void* fn_92_5024(void* object, short deleting) {
    if (object != 0) {
        fn_92_9EB8(static_cast<unsigned char*>(object) + 0xE0, -1);
        fn_92_509C(static_cast<unsigned char*>(object) + 0x30, -1);
        fn_92_510C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
