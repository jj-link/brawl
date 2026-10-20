#pragma force_active on
void operator delete(void*);
extern "C" void* fn_115_17B5C(void* object, short deleting);
extern "C" void fn_115_17A84(void* object, short deleting);

extern "C" void* fn_115_17BBC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_115_17B5C(storage + 0xA4, -1);
        if (object != 0) {
            fn_115_17A84(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
