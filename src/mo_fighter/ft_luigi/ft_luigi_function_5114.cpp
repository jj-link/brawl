#pragma force_active on
extern "C" {
void* fn_27_150488(void*, short);
void* fn_27_199A54(void*, short);
void fn_99_5194(void*, short);
}

extern "C" void* fn_99_5114(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_150488(storage + 0x5b8, -1);
        fn_99_5194(storage + 0x584, -1);
        if (object) fn_27_199A54(object, -1);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
