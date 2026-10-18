#pragma force_active on
extern "C" {
void* fn_96_4CE8(void* object, short deleting);
void* fn_96_4C88(void* object, short deleting);
void* fn_96_2F400(void* object, short deleting);
void* fn_96_7D5C(void* object, short deleting);
void* fn_96_2F45C(void* object, short deleting);
void* fn_27_C74E8(void* object, short deleting);
}

void operator delete(void*);

extern "C" void* fn_96_2F364(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_96_4CE8(storage + 0x124, -1);
        fn_96_4C88(storage + 0x110, -1);
        fn_96_2F400(storage + 0xF4, -1);
        fn_96_7D5C(storage + 0x50, -1);
        fn_96_2F45C(storage + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
