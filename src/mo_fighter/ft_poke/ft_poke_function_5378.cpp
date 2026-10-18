#pragma force_active on
void operator delete(void*);
extern "C" void* fn_116_4EB8(void*, short);

extern "C" void* fn_116_5378(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        fn_116_4EB8(members + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
