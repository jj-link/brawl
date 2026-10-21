#pragma force_active on
extern "C" void* fn_104_38E0(void* object, short deleting);
extern "C" void* fn_104_394C(void* object, short deleting);
extern "C" void* fn_104_39D8(void* object, short deleting);
extern "C" void* fn_104_3A64(void* object, short deleting);
extern "C" void* fn_104_11AB0(void* object, short deleting);
void operator delete(void*);

extern "C" void* fn_104_11A20(void* object, short deleting) {
    if (object != 0) {
        short flag = -1;
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_104_38E0(storage + 0x4B0, flag);
        fn_104_394C(storage + 0x384, flag);
        fn_104_39D8(storage + 0x258, flag);
        fn_104_3A64(storage + 0x12C, flag);
        fn_104_11AB0(object, flag);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
