#pragma force_active on
void operator delete(void*);
extern "C" void* fn_115_4118(void*, short);
extern "C" void* fn_115_447C(void*, short);

extern "C" void* fn_115_4410(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_115_4118(storage + 0x3F80, -1);
        fn_115_447C(storage + 0x4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
