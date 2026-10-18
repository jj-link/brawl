#pragma force_active on
void operator delete(void*);

extern "C" void* fn_27_565F0(void*, short);

extern "C" void* fn_121_7154(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        fn_27_565F0(members + 0xC, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
