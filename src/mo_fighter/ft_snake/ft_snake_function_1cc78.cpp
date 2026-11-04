#include <so/so_module_accesser.h>
#include <sr/sr_common.h>
#pragma force_active on

extern "C" void* fn_122_3BC4(void*, short);
extern "C" void* fn_122_3C20(void*, short);
extern "C" void* fn_122_3C7C(void*, short);
extern "C" void* fn_122_6498(void*, short);
extern "C" void* fn_122_3D5C(void*, short);
extern "C" void* fn_122_3DE8(void*, short);
extern "C" void* fn_122_57B0(void*, short);
extern "C" void* fn_122_1CE10(void*, short);
extern "C" void* fn_122_430C(void*, short);
extern "C" void* fn_122_4440(void*, short);
extern "C" void* fn_122_44FC(void*, short);
extern "C" void* fn_122_4558(void*, short);
extern "C" void* fn_122_45C4(void*, short);
extern "C" void* fn_122_4624(void*, short);
extern "C" void* fn_122_4684(void*, short);
extern "C" void* fn_122_47CC(void*, short);
extern "C" void* fn_122_5998(void*, short);
extern "C" void* fn_122_4850(void*, short);
extern "C" void* fn_122_491C(void*, short);
extern "C" void* fn_122_5B54(void*, short);
extern "C" void* fn_122_64F4(void*, short);
extern "C" void* fn_122_4B58(void*, short);
extern "C" void* fn_122_4BC4(void*, short);
extern "C" void* fn_122_4C7C(void*, short);
extern "C" void* fn_122_4CBC(void*, short);
extern "C" void* fn_122_4D18(void*, short);

extern "C" void* fn_122_1CC78(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_122_3BC4(storage + 0x1AFC, -1);
        fn_122_3C20(storage + 0x1ABC, -1);
        fn_122_3C7C(storage + 0x1AA4, -1);
        fn_122_6498(storage + 0x194C, -1);
        fn_122_3D5C(storage + 0x17B4, -1);
        fn_122_3DE8(storage + 0x1754, -1);
        fn_122_57B0(storage + 0x16A0, -1);
        fn_122_1CE10(storage + 0x14D4, -1);
        fn_122_430C(storage + 0x1430, -1);
        fn_122_4440(storage + 0x13FC, -1);
        fn_122_44FC(storage + 0x13E4, -1);
        fn_122_4558(storage + 0x1280, -1);
        fn_122_45C4(storage + 0x1218, -1);
        fn_122_4624(storage + 0x120C, -1);
        fn_122_4684(storage + 0x11E4, -1);
        fn_122_47CC(storage + 0x1038, -1);
        fn_122_5998(storage + 0xE74, -1);
        fn_122_4850(storage + 0xE10, -1);
        fn_122_491C(storage + 0xDD4, -1);
        fn_122_5B54(storage + 0xD1C, -1);
        fn_122_64F4(storage + 0xB10, -1);
        fn_122_4B58(storage + 0x930, -1);
        fn_122_4BC4(storage + 0x900, -1);
        fn_122_4C7C(storage + 0x8F0, -1);
        fn_122_4CBC(storage + 0x8D8, -1);
        reinterpret_cast<soModuleAccesser*>(storage + 0x7F8)->soModuleAccesser::~soModuleAccesser();
        fn_122_4D18(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
