#pragma force_active on
void operator delete(void*);

extern "C" void fn_105_5BD4(void*, short);

extern "C" void* fn_105_5B74(void* object, short deleting) {
    if (object != 0) {
        fn_105_5BD4(static_cast<char*>(object) + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
