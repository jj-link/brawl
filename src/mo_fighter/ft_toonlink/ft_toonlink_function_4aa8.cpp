#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A1B88(void* member, short deleteFlag);
extern "C" void* fn_121_4A38(void* object, short deleting);

extern "C" void* fn_121_4AA8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A1B88(storage + 0x88, -1);
        if (object != 0) {
            fn_121_4A38(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
