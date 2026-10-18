#pragma force_active on
void operator delete(void*);

extern "C" void fn_112_383C(void*, short);

extern "C" void* fn_112_4A14(void* object, short deleting) {
    if (object != 0) {
        fn_112_383C(static_cast<unsigned char*>(object) + 0x14, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
