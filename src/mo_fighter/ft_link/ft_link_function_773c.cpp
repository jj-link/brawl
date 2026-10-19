#pragma force_active on
void operator delete(void*);
extern "C" void fn_93_78A8(void*, short);
extern "C" void* fn_93_76DC(void*, short);

extern "C" void* fn_93_773C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_93_78A8(storage + 0x1fe8, -1);
        fn_93_76DC(storage + 0x4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
