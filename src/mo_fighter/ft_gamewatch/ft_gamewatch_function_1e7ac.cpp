#pragma force_active on
void operator delete(void*);
extern "C" void* fn_107_1E81C(void*, short);
extern "C" void* fn_107_1EADC(void*, short);

extern "C" void* fn_107_1E7AC(void* object, short deleting) {
    if (object != 0) {
        fn_107_1E81C(static_cast<unsigned char*>(object) + 0x21C4, -1);
        fn_107_1EADC(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
