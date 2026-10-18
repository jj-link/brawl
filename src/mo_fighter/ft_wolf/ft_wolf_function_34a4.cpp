#pragma force_active on
void operator delete(void*);

extern "C" void fn_125_3504(void*, short);

extern "C" void* fn_125_34A4(void* object, short deleting) {
    if (object != 0) {
        fn_125_3504(static_cast<char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
