#pragma force_active on
void operator delete(void*);

extern "C" void fn_122_7050(void*, short);

extern "C" void* fn_122_6FF0(void* object, short deleting) {
    if (object != 0) {
        fn_122_7050(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
