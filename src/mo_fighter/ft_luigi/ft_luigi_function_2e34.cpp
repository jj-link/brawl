#pragma force_active on
extern "C" {
void* fn_27_10424(void*, short);
void* fn_27_19A97C(void*, short);
}

extern "C" void* fn_99_2E34(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_10424(storage + 0x7C, -1);
        if (object) fn_27_19A97C(object, -1);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
