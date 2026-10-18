#pragma force_active on
extern "C" void* fn_93_D0D0(void*, short);
void operator delete(void*);

extern "C" void* fn_93_D130(void* object, short deleting) {
    if (object != 0) {
        fn_93_D0D0(static_cast<char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
