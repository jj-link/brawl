#pragma force_active on
extern "C" void* fn_92_2178(void* object, short deleting);
extern "C" void* fn_92_233C(void* object, short deleting);
extern "C" void* fn_92_2404(void* object, short deleting);
extern "C" void* fn_92_2490(void* object, short deleting);
extern "C" void* fn_92_251C(void* object, short deleting);
extern "C" void* fn_92_25A8(void* object, short deleting);
extern "C" void* fn_92_2634(void* object, short deleting);
extern "C" void* fn_92_26C0(void* object, short deleting);
extern "C" void* fn_92_274C(void* object, short deleting);
extern "C" void* fn_92_27D8(void* object, short deleting);
extern "C" void* fn_92_2864(void* object, short deleting);

extern "C" void operator delete(void*);

extern "C" void* fn_92_20A0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_92_2178(storage + 0x1560, -1);
        fn_92_233C(storage + 0x143C, -1);
        fn_92_2404(storage + 0x1310, -1);
        fn_92_2490(storage + 0x11E4, -1);
        fn_92_251C(storage + 0x10B8, -1);
        fn_92_25A8(storage + 0xF8C, -1);
        fn_92_2634(storage + 0xE60, -1);
        fn_92_26C0(storage + 0xD34, -1);
        fn_92_274C(storage + 0xC08, -1);
        fn_92_27D8(storage + 0xADC, -1);
        fn_92_2864(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}