#pragma force_active on
void operator delete(void*);
extern "C" void* fn_107_15EB4(void* object, short deleting);
extern "C" void* fn_107_4F74(void* object, short deleting);

extern "C" void* fn_107_15E44(void* object, short deleting) {
    if (object != 0) {
        fn_107_4F74(static_cast<unsigned char*>(object) + 0x1990, -1);
        fn_107_15EB4(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
