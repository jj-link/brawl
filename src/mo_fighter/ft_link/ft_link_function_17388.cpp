#pragma force_active on
void operator delete(void*);
extern "C" void* fn_93_173F8(void*, short);
extern "C" void* fn_93_5F68(void*, short);

extern "C" void* fn_93_17388(void* object, short deleting) {
    if (object != 0) {
        fn_93_173F8(static_cast<unsigned char*>(object) + 0x8, -1);
        fn_93_5F68(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
