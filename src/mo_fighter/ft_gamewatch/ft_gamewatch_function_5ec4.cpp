#pragma force_active on
void operator delete(void*);
extern "C" void fn_107_5F24(void*, short);

extern "C" void* fn_107_5EC4(void* object, short deleting) {
    if (object != 0) {
        fn_107_5F24(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
