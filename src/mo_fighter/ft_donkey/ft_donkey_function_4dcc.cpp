#pragma force_active on
void operator delete(void*);
extern "C" void* fn_92_4914(void*, short);
extern "C" void* fn_92_4E38(void*, short);

extern "C" void* fn_92_4DCC(void* object, short deleting) {
    if (object != 0) {
        fn_92_4914(static_cast<unsigned char*>(object) + 0x3FB0, -1);
        fn_92_4E38(static_cast<unsigned char*>(object) + 0x4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
