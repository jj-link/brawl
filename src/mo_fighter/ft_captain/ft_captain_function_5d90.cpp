#pragma force_active on
extern "C" {
void* fn_27_6A3D8(void*, short);
void* fn_27_199BBC(void*, short);
void operator delete(void*);
}

// Module destructor: destroy the embedded sub-module, then the base, then the object.
extern "C" void* fn_100_5D90(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        fn_27_6A3D8(storage + 0x27C, -1);
        fn_27_199BBC(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
