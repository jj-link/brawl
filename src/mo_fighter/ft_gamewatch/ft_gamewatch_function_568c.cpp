#pragma force_active on
extern "C" void fn_107_5704(void* object, short deleting);
extern "C" void fn_107_5AC8(void* object, short deleting);

extern "C" void* fn_107_568C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_107_5704(storage + 0x6B04, -1);
        if (object != 0) {
            fn_107_5AC8(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
