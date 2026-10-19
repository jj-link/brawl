#pragma force_active on
void operator delete(void*);
extern "C" void* fn_92_4914(void*, short);
extern "C" void* fn_92_4DCC(void*, short);

extern "C" void* fn_92_48A8(void* object, short deleting) {
    if (object != 0) {
        fn_92_4914(static_cast<char*>(object) + 0x5f84, -1);
        fn_92_4DCC(static_cast<char*>(object) + 0x4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
