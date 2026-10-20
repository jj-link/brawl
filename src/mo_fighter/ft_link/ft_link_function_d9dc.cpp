#pragma force_active on
void operator delete(void*);
extern "C" void* fn_93_D97C(void* object, short deleting);
extern "C" void fn_93_D848(void* object, short deleting);

extern "C" void* fn_93_D9DC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_93_D97C(storage + 0x204, -1);
        if (object != 0) {
            fn_93_D848(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
