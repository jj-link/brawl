#pragma force_active on
void operator delete(void*);
extern "C" void fn_107_E178(void*, short);

extern "C" void* fn_107_E1D8(void* object, short deleting) {
    if (object != 0) {
        fn_107_E178(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
