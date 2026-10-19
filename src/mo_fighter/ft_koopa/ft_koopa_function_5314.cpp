#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_565F0(void*, short);
extern "C" void* fn_102_5380(void*, short);

extern "C" void* fn_102_5314(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_565F0(storage + 0x14, -1);
        fn_102_5380(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
