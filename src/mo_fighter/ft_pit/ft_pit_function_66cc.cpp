#pragma force_active on
void operator delete(void*);
extern "C" void fn_27_1A2524(void*, short);
extern "C" void* fn_112_4AFC(void* p, short n);

extern "C" void* fn_112_66CC(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A2524(static_cast<unsigned char*>(object) + 0x10, -1);
        fn_112_4AFC(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
