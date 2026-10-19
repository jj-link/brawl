#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_565F0(void*, short);
extern "C" void* fn_117_57BC(void*, short);

extern "C" void* fn_117_5750(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_27_565F0(storage + 0x14, memberDeleting);
        fn_117_57BC(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
