#pragma force_active on
void operator delete(void*);
extern "C" void* fn_118_BA90(void*, short);
extern "C" void* fn_118_B960(void*, short);

extern "C" void* fn_118_BAF0(void* object, short deleting) {
    if (object != 0) {
        fn_118_BA90(static_cast<unsigned char*>(object) + 0x94, -1);
        if (object != 0) {
            fn_118_B960(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
