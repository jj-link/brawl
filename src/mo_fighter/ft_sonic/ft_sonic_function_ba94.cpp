#pragma force_active on
void operator delete(void*);
extern "C" void* fn_123_BA34(void* object, short deleting);
extern "C" void* fn_123_B904(void* object, short deleting);

extern "C" void* fn_123_BA94(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_123_BA34(storage + 0x94, -1);
        if (object != 0) {
            fn_123_B904(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
