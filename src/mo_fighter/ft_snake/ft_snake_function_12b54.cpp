#pragma force_active on
void operator delete(void*);

extern "C" void fn_122_12AF4(void*, short);

extern "C" void* fn_122_12B54(void* object, short deleting) {
    if (object != 0) {
        fn_122_12AF4(static_cast<unsigned char*>(object) + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
