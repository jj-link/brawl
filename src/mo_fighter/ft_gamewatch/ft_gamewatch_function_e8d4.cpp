#pragma force_active on
void operator delete(void*);
extern "C" void fn_107_E874(void*, short);

extern "C" void* fn_107_E8D4(void* object, short deleting) {
    if (object != 0) {
        fn_107_E874(static_cast<unsigned char*>(object) + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
