void operator delete(void*);
extern "C" void* fn_118_39D0(void*, short);
extern "C" void* fn_118_3A2C(void*, short);
extern "C" void* fn_118_3A88(void*, short);
extern "C" void* fn_118_3AE4(void*, short);
extern "C" void* fn_118_133C4(void*, short);
extern "C" void* fn_118_3C0C(void*, short);
extern "C" void* fn_118_13424(void*, short);
extern "C" void* fn_118_3FB4(void*, short);
extern "C" void* fn_118_40E8(void*, short);
extern "C" void* fn_118_4144(void*, short);
extern "C" void* fn_118_41A0(void*, short);
extern "C" void* fn_118_420C(void*, short);
extern "C" void* fn_118_426C(void*, short);
extern "C" void* fn_118_42CC(void*, short);
extern "C" void* fn_118_1351C(void*, short);
extern "C" void* fn_118_4328(void*, short);
extern "C" void* fn_118_43F4(void*, short);
extern "C" void* fn_118_44BC(void*, short);
extern "C" void* fn_118_4530(void*, short);
extern "C" void* fn_118_459C(void*, short);
extern "C" void* fn_118_4654(void*, short);
extern "C" void* fn_118_4694(void*, short);
extern "C" void* __dt__16soModuleAccesserFv(void*, short);
extern "C" void* fn_118_46F0(void*, short);

// Each subobject retains its original destructor and inline storage ownership.
extern "C" void* fn_118_13250(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_118_39D0(storage + 0x16F8, -1);
        fn_118_3A2C(storage + 0x16B8, -1);
        fn_118_3A88(storage + 0x16A0, -1);
        fn_118_3AE4(storage + 0x1504, -1);
        fn_118_133C4(storage + 0x14C0, -1);
        fn_118_3C0C(storage + 0x140C, -1);
        fn_118_13424(storage + 0x124C, -1);
        fn_118_3FB4(storage + 0x11A8, -1);
        fn_118_40E8(storage + 0x1174, -1);
        fn_118_4144(storage + 0x115C, -1);
        fn_118_41A0(storage + 0xFF8, -1);
        fn_118_420C(storage + 0xF90, -1);
        fn_118_426C(storage + 0xF84, -1);
        fn_118_42CC(storage + 0xF5C, -1);
        fn_118_1351C(storage + 0xC6C, -1);
        fn_118_4328(storage + 0xC08, -1);
        fn_118_43F4(storage + 0xBCC, -1);
        fn_118_44BC(storage + 0xB14, -1);
        fn_118_4530(storage + 0x930, -1);
        fn_118_459C(storage + 0x900, -1);
        fn_118_4654(storage + 0x8F0, -1);
        fn_118_4694(storage + 0x8D8, -1);
        __dt__16soModuleAccesserFv(storage + 0x7F8, -1);
        fn_118_46F0(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
