#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_565F0(void*, short);
extern "C" void* fn_109_10BFC(void*, short);

extern "C" void* fn_109_10B90(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_565F0(storage + 0xC, -1);
        fn_109_10BFC(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
