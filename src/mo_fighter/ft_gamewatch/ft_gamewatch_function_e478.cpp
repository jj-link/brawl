#pragma force_active on
void operator delete(void*);
extern "C" void* fn_107_E418(void*, short);
extern "C" void* fn_107_E2F8(void*, short);

extern "C" void* fn_107_E478(void* object, short deleting) {
    if (object != 0) {
        fn_107_E418(static_cast<unsigned char*>(object) + 0x60, -1);
        fn_107_E2F8(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
