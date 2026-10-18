#pragma force_active on
extern "C" void fn_92_1F64(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_92_3DC0(void* object, short deleting) {
    if (object != 0) {
        fn_92_1F64(static_cast<char*>(object) + 8, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
