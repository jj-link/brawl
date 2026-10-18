#pragma force_active on
void operator delete(void*);
extern "C" void fn_95_5DD8(void*, short);

extern "C" void* fn_95_60D8(void* object, short deleting) {
    if (object != 0) {
        fn_95_5DD8(static_cast<char*>(object) + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
