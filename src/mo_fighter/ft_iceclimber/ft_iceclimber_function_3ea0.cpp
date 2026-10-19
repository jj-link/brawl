#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_27_75E0C(void*, short);
void fn_105_3F1C(void*, short);
void fn_105_1EEC(void*, short);

void* fn_105_3EA0(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        fn_27_75E0C(storage + 0x4C, -1);
        fn_105_3F1C(storage + 0x20, 0);
        fn_105_1EEC(storage + 0x14, 0);

        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
}
