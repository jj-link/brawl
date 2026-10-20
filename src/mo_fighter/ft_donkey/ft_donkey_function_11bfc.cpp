#pragma force_active on
void operator delete(void*);
extern "C" void* fn_92_3A38(void*, short);
extern "C" void* fn_92_11C8C(void*, short);
extern "C" void* fn_92_11D18(void*, short);
extern "C" void* fn_92_11DA4(void*, short);
extern "C" void* fn_92_11E30(void*, short);

extern "C" void* fn_92_11BFC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_92_3A38(storage + 0x4B0, -1);
        fn_92_11C8C(storage + 0x384, -1);
        fn_92_11D18(storage + 0x258, -1);
        fn_92_11DA4(storage + 0x12C, -1);
        fn_92_11E30(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
