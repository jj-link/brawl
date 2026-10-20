#pragma force_active on
extern "C" void fn_27_D2904(void* member, short deleteFlag);
extern "C" void fn_115_5300(void* object, short deleting);
void operator delete(void*);

extern "C" void* fn_115_5288(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_D2904(storage + 0xb4, -1);
        if (object != 0) {
            fn_115_5300(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
