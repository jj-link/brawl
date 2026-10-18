#pragma force_active on
extern "C" void* fn_96_124D4(void*, short);
void operator delete(void*);

extern "C" void* fn_96_F910(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_96_124D4(static_cast<unsigned char*>(object) + 4, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
