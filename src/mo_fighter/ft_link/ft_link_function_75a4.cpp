#pragma force_active on
void operator delete(void*);
extern "C" void fn_93_13848(void*, short);

extern "C" void* fn_93_75A4(void* object, short deleting) {
    if (object != 0) {
        fn_93_13848(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
