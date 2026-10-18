#pragma force_active on
void operator delete(void*);
extern "C" void fn_95_3584(void*, short);

extern "C" void* fn_95_4B40(void* object, short deleting) {
    if (object != 0) {
        fn_95_3584(static_cast<unsigned char*>(object) + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
