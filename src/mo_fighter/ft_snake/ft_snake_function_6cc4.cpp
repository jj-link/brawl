#pragma force_active on
void operator delete(void*);

extern "C" void fn_122_6D24(void*, short);

extern "C" void* fn_122_6CC4(void* object, short deleting) {
    if (object != 0) {
        fn_122_6D24(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
