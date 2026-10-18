#pragma force_active on
extern "C" void fn_123_1473C(void*, short);
extern "C" void fn_123_39EC(void*, short);
extern "C" void fn_123_147C8(void*, short);
extern "C" void fn_123_14854(void*, short);
extern "C" void fn_123_148E0(void*, short);
extern "C" void fn_123_3A58(void*, short);

extern "C" void* fn_123_146A0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_123_1473C(storage + 0x5ac, -1);
        fn_123_39EC(storage + 0x4b0, -1);
        fn_123_147C8(storage + 0x384, -1);
        fn_123_14854(storage + 0x258, -1);
        fn_123_148E0(storage + 0x12c, -1);
        fn_123_3A58(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
