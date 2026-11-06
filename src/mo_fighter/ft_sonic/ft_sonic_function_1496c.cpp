#pragma force_active on
void operator delete(void*);
extern "C" void* fn_123_3AE4(void*, short);
extern "C" void* fn_123_3B40(void*, short);
extern "C" void* fn_123_14B28(void*, short);
extern "C" void* fn_123_2E14(void*, short);
extern "C" void* fn_123_14B84(void*, short);
extern "C" void* fn_123_3B9C(void*, short);
extern "C" void* fn_123_14C10(void*, short);
extern "C" void* fn_123_3D38(void*, short);
extern "C" void* fn_123_3FA0(void*, short);
extern "C" void* fn_123_40D4(void*, short);
extern "C" void* fn_123_4F40(void*, short);
extern "C" void* fn_123_14C88(void*, short);
extern "C" void* fn_123_4130(void*, short);
extern "C" void* fn_123_418C(void*, short);
extern "C" void* fn_123_41F8(void*, short);
extern "C" void* fn_123_4258(void*, short);
extern "C" void* fn_123_42B8(void*, short);
extern "C" void* fn_123_4FB4(void*, short);
extern "C" void* fn_123_4314(void*, short);
extern "C" void* fn_123_4398(void*, short);
extern "C" void* fn_123_4464(void*, short);
extern "C" void* fn_123_44C0(void*, short);
extern "C" void* fn_123_452C(void*, short);
extern "C" void* fn_123_14D44(void*, short);
extern "C" void* fn_123_4628(void*, short);
extern "C" void* fn_123_4694(void*, short);
extern "C" void* fn_123_474C(void*, short);
extern "C" void* fn_123_478C(void*, short);
extern "C" void* __dt__16soModuleAccesserFv(void*, short);
extern "C" void* fn_123_14DC8(void*, short);

extern "C" void* fn_123_1496C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_123_3AE4(storage + 0x24E8, -1);
        fn_123_3B40(storage + 0x24D0, -1);
        fn_123_14B28(storage + 0x2378, -1);
        fn_123_2E14(storage + 0x232C, -1);
        fn_123_14B84(storage + 0x2194, -1);
        fn_123_3B9C(storage + 0x2134, -1);
        fn_123_14C10(storage + 0x1FEC, -1);
        fn_123_3D38(storage + 0x1E20, -1);
        fn_123_3FA0(storage + 0x1D7C, -1);
        fn_123_40D4(storage + 0x1D48, -1);
        fn_123_4F40(storage + 0x1CD4, -1);
        fn_123_14C88(storage + 0x1CB4, -1);
        fn_123_4130(storage + 0x1CA0, -1);
        fn_123_418C(storage + 0x1B3C, -1);
        fn_123_41F8(storage + 0x1AD4, -1);
        fn_123_4258(storage + 0x1AC8, -1);
        fn_123_42B8(storage + 0x1AA0, -1);
        fn_123_4FB4(storage + 0x113C, -1);
        fn_123_4314(storage + 0xF78, -1);
        fn_123_4398(storage + 0xF14, -1);
        fn_123_4464(storage + 0xED8, -1);
        fn_123_44C0(storage + 0xE30, -1);
        fn_123_452C(storage + 0xD7C, -1);
        fn_123_14D44(storage + 0xB34, -1);
        fn_123_4628(storage + 0x954, -1);
        fn_123_4694(storage + 0x924, -1);
        fn_123_474C(storage + 0x914, -1);
        fn_123_478C(storage + 0x8FC, -1);
        __dt__16soModuleAccesserFv(storage + 0x81C, -1);
        fn_123_14DC8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
