#pragma force_active on
void operator delete(void*);
extern "C" void* fn_107_1A544(void*, short);
extern "C" void* fn_107_1A778(void*, short);

extern "C" void* fn_107_1A4D4(void* object, short deleting) {
    if (object != 0) {
        fn_107_1A544(static_cast<unsigned char*>(object) + 0x19AC, -1);
        fn_107_1A778(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
