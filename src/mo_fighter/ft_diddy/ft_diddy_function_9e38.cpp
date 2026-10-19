#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_C74E8(void*, short);
extern "C" void* fn_115_1954(void*, short);

extern "C" void* fn_115_9E38(void* object, short deleting) {
    if (object != 0) {
        fn_27_C74E8(static_cast<unsigned char*>(object) + 0x26870, -1);
        fn_115_1954(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
