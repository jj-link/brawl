#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_CB048(void*, short);
extern "C" void* fn_27_199214(void*, short);
extern "C" void* fn_27_A78FC(void*, short);
extern "C" void* fn_27_14E050(void*, short);
extern "C" void* fn_27_197EF4(void*, short);

extern "C" void* fn_105_2F54(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_CB048(storage + 0x220, -1);
        fn_27_199214(storage + 0x94, -1);
        fn_27_A78FC(storage + 0x78, -1);
        fn_27_14E050(storage + 0x10, -1);
        if (object != 0) {
            fn_27_197EF4(object, -1);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
