#pragma force_active on
extern "C" void fn_99_A0C4(void*, short);
extern "C" void operator delete(void*);

extern "C" void* fn_99_A124(void* object, short deleting) {
    if (object) {
        fn_99_A0C4(static_cast<unsigned char*>(object) + 8, -1);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
