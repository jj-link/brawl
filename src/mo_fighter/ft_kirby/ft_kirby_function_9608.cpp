#pragma force_active on
extern "C" void* fn_96_95A8(void* object, short deleting);
extern "C" void fn_96_9294(void* object, short flag);
void operator delete(void*);

extern "C" void* fn_96_9608(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_96_95A8(storage + 0x10F6C, -1);
        if (object != 0) {
            fn_96_9294(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
