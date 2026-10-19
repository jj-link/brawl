#pragma force_active on
extern "C" void* fn_121_7BF4(void* object, short deleting);
extern "C" void* fn_121_7974(void* object, short deleting);

void operator delete(void*);

extern "C" void* fn_121_7C54(void* object, short deleting) {
    if (object != 0) {
        fn_121_7BF4(static_cast<unsigned char*>(object) + 0x106F4, -1);
        if (object != 0) {
            fn_121_7974(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
