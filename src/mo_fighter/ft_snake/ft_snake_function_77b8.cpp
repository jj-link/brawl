#pragma force_active on
void operator delete(void*);

extern "C" void fn_122_7818(void*, short);
extern "C" void* fn_122_77B8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        fn_122_7818(members + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
