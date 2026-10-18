#pragma force_active on
void operator delete(void*);
extern "C" void fn_113_1C40C(void*, short);

extern "C" void* fn_113_1C468(void* object, short deleting) {
    if (object != 0) {
        fn_113_1C40C(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
