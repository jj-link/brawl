#pragma force_active on
void operator delete(void*);
extern "C" void* fn_93_7BF4(void* object, short deleting);
extern "C" void* fn_93_7974(void* object, short deleting);

extern "C" void* fn_93_7C54(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_93_7BF4(storage + 0x106F4, -1);
        if (object != 0) {
            fn_93_7974(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
