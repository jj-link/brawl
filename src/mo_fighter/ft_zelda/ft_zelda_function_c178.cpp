#pragma force_active on
void operator delete(void*);
extern "C" void fn_104_C118(void*, short);

extern "C" void* fn_104_C178(void* object, short deleting) {
    if (object != 0) {
        fn_104_C118(static_cast<char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
