#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_6880C(void*, short);

extern "C" void* fn_119_11C98(void* object, short deleting) {
    if (object != 0) {
        fn_27_6880C(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
