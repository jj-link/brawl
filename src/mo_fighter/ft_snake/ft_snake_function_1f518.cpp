#pragma force_active on
extern "C" void* fn_122_3BC4(void*, short);
extern "C" void* fn_122_3C20(void*, short);
extern "C" void* fn_122_3C7C(void*, short);
extern "C" void* fn_122_3CD8(void*, short);
extern "C" void* fn_122_3D5C(void*, short);
extern "C" void* fn_122_3DE8(void*, short);
extern "C" void* fn_122_1F6E0(void*, short);
extern "C" void* fn_122_1F758(void*, short);
extern "C" void* fn_122_430C(void*, short);
extern "C" void* fn_122_4440(void*, short);
extern "C" void* fn_122_449C(void*, short);
extern "C" void* fn_122_44FC(void*, short);
extern "C" void* fn_122_4558(void*, short);
extern "C" void* fn_122_45C4(void*, short);
extern "C" void* fn_122_4624(void*, short);
extern "C" void* fn_122_4684(void*, short);
extern "C" void* fn_122_46E0(void*, short);
extern "C" void* fn_122_4754(void*, short);
extern "C" void* fn_122_47CC(void*, short);
extern "C" void* fn_122_1F850(void*, short);
extern "C" void* fn_122_4850(void*, short);
extern "C" void* fn_122_491C(void*, short);
extern "C" void* fn_122_4978(void*, short);
extern "C" void* fn_122_49E4(void*, short);
extern "C" void* fn_122_4A58(void*, short);
extern "C" void* fn_122_4B58(void*, short);
extern "C" void* fn_122_4BC4(void*, short);
extern "C" void* fn_122_4C7C(void*, short);
extern "C" void* fn_122_4CBC(void*, short);
extern "C" void __dt__16soModuleAccesserFv(void*, short);
extern "C" void* fn_122_4D18(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_122_1F518(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_122_3BC4(storage + 0x20E8, -1);
        fn_122_3C20(storage + 0x20A8, -1);
        fn_122_3C7C(storage + 0x2090, -1);
        fn_122_3CD8(storage + 0x1F7C, -1);
        fn_122_3D5C(storage + 0x1DE8, -1);
        fn_122_3DE8(storage + 0x1D88, -1);
        fn_122_1F6E0(storage + 0x1CA4, -1);
        fn_122_1F758(storage + 0x1AD4, -1);
        fn_122_430C(storage + 0x1A30, -1);
        fn_122_4440(storage + 0x19FC, -1);
        fn_122_449C(storage + 0x19E0, -1);
        fn_122_44FC(storage + 0x19C8, -1);
        fn_122_4558(storage + 0x1864, -1);
        fn_122_45C4(storage + 0x17FC, -1);
        fn_122_4624(storage + 0x17F0, -1);
        fn_122_4684(storage + 0x17C8, -1);
        fn_122_46E0(storage + 0x166C, -1);
        fn_122_4754(storage + 0x1474, -1);
        fn_122_47CC(storage + 0x12CC, -1);
        fn_122_1F850(storage + 0xF78, -1);
        fn_122_4850(storage + 0xF14, -1);
        fn_122_491C(storage + 0xED8, -1);
        fn_122_4978(storage + 0xE30, -1);
        fn_122_49E4(storage + 0xD1C, -1);
        fn_122_4A58(storage + 0xB10, -1);
        fn_122_4B58(storage + 0x930, -1);
        fn_122_4BC4(storage + 0x900, -1);
        fn_122_4C7C(storage + 0x8F0, -1);
        fn_122_4CBC(storage + 0x8D8, -1);
        __dt__16soModuleAccesserFv(storage + 0x7F8, -1);
        fn_122_4D18(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}