#pragma force_active on
void operator delete(void*);
extern "C" void fn_112_E808(void*, short);
extern "C" void* fn_112_E924(void*, short);

extern "C" void* fn_112_E798(void* object, short deleting) {
    if (object != 0) {
        fn_112_E808(static_cast<unsigned char*>(object) + 0x1C48, -1);
        fn_112_E924(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
