#pragma force_active on
void operator delete(void*);
extern "C" void* fn_118_1F78(void*, short);
extern "C" void* fn_118_3CE8(void*, short);

extern "C" void* fn_118_4FE0(void* object, short deleting) {
    if (object != 0) {
        fn_118_1F78(static_cast<unsigned char*>(object) + 0x20, 0);
        fn_118_3CE8(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
