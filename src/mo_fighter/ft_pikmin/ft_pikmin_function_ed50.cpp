#pragma force_active on
void operator delete(void*);
extern "C" void fn_113_ECF0(void*, short);

extern "C" void* fn_113_ED50(void* object, short deleting) {
    if (object != 0) {
        fn_113_ECF0(static_cast<char*>(object) + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
