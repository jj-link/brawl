#pragma force_active on
extern "C" void* fn_121_78A8(void* object, short deleting);
extern "C" void* fn_121_77A8(void* object, short deleting);

extern "C" void* fn_121_7908(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_121_78A8(storage + 0x5FA8, -1);
        fn_121_77A8(storage + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
