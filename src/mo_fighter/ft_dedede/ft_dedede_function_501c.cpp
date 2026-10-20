#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A15B8(void*, short);
extern "C" void fn_117_5094(void*, short);

extern "C" void* fn_117_501C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A15B8(storage + 0x138, -1);
        if (object != 0) {
            fn_117_5094(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
