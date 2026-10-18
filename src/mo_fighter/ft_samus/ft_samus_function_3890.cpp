#pragma force_active on
void operator delete(void*);
extern "C" void fn_27_2ED710(void*, short);

extern "C" void* fn_94_3890(void* object, short deleting) {
    if (object != 0) {
        fn_27_2ED710(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
