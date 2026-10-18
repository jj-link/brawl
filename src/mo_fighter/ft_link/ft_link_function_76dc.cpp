#pragma force_active on
void operator delete(void*);
extern "C" void fn_93_78A8(void*, short);

extern "C" void* fn_93_76DC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        fn_93_78A8(members + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
