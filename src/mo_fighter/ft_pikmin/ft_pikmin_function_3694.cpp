#pragma force_active on
extern "C" {
void* fn_113_2068(void*, short);
void* fn_113_3704(void*, short);
}

extern "C" void* fn_113_3694(void* object, short deleting) {
    if (object != 0) {
        fn_113_2068(static_cast<unsigned char*>(object) + 0xCD38, static_cast<short>(-1));
        fn_113_3704(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
