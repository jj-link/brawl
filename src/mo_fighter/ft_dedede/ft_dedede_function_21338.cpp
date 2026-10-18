#pragma force_active on
extern "C" void fn_117_212D8(void*, short);
void operator delete(void*);

extern "C" void* fn_117_21338(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_117_212D8(storage + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
