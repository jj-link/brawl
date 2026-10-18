#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_150488(void*, short);
extern "C" void* fn_118_5D8C(void*, short);
extern "C" void* fn_27_199A54(void*, short);

extern "C" void* fn_118_5D0C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_150488(storage + 0x5B8, -1);
        fn_118_5D8C(storage + 0x584, -1);
        if (object != 0) {
            fn_27_199A54(object, -1);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
