#pragma force_active on
extern "C" void* fn_27_1A1E70(void*, short);
extern "C" void* fn_99_4F04(void*, short);

extern "C" void* fn_99_4E94(void* object, short deleting) {
    if (object) {
        fn_27_1A1E70(static_cast<char*>(object) + 0x1C, -1);
        fn_99_4F04(object, 0);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
