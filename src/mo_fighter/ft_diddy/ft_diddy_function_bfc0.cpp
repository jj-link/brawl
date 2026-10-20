#pragma force_active on
void operator delete(void*);
extern "C" void* fn_115_BF60(void* object, short deleting);
extern "C" void* fn_115_BE30(void* object, short deleting);

extern "C" void* fn_115_BFC0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_115_BF60(storage + 0x94, -1);
        if (object != 0) {
            fn_115_BE30(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
