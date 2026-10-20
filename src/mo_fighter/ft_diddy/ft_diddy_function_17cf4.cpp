#pragma force_active on
extern "C" void* fn_115_17C94(void* object, short deleting);
extern "C" void* fn_115_17BBC(void* object, short deleting);
extern "C" void operator delete(void* ptr);

extern "C" void* fn_115_17CF4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_115_17C94(storage + 0xE0, -1);
        if (object != 0) {
            fn_115_17BBC(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
