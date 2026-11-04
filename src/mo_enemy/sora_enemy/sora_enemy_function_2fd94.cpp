#include <types.h>
#pragma force_active on

extern "C" {
void* fn_41_2FD38(void*, short);
void* fn_41_2FCDC(void*, short);
void* fn_41_2FC80(void*, short);
void* fn_41_2FC24(void*, short);
void* fn_41_2FB98(void*, short);
void* fn_41_2FADC(void*, short);
void* fn_41_2FA70(void*, short);
void* fn_41_2F9A4(void*, short);
void* fn_41_2F944(void*, short);
void* fn_41_2F8E8(void*, short);
void* fn_41_2F87C(void*, short);
void* fn_41_2F810(void*, short);
void* fn_41_2F79C(void*, short);
void* fn_41_2F740(void*, short);
void* fn_41_2F6CC(void*, short);
void* fn_41_2F654(void*, short);
void* fn_41_2F5D0(void*, short);
void* fn_41_2F54C(void*, short);
void* fn_41_2F488(void*, short);
void* fn_41_2F3D4(void*, short);
void* fn_41_2F368(void*, short);
void* fn_41_2F2F4(void*, short);
void* fn_41_2F264(void*, short);
void* fn_41_2F000(void*, short);
void* fn_41_2EF2C(void*, short);
void* fn_41_2EECC(void*, short);
void* fn_41_2EDD4(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_41_2ECE4(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_41_2FD94(void* self, short del) {
    if (self != 0) {
        short destroy = -1;
        fn_41_2FD38(static_cast<char*>(self) + 0x1D2C, destroy);
        fn_41_2FCDC(static_cast<char*>(self) + 0x1CEC, destroy);
        fn_41_2FC80(static_cast<char*>(self) + 0x1CD4, destroy);
        fn_41_2FC24(static_cast<char*>(self) + 0x1B7C, destroy);
        fn_41_2FB98(static_cast<char*>(self) + 0x19E4, destroy);
        fn_41_2FADC(static_cast<char*>(self) + 0x1984, destroy);
        fn_41_2FA70(static_cast<char*>(self) + 0x18CC, destroy);
        fn_41_2F9A4(static_cast<char*>(self) + 0x1898, destroy);
        fn_41_2F944(static_cast<char*>(self) + 0x187C, destroy);
        fn_41_2F8E8(static_cast<char*>(self) + 0x1864, destroy);
        fn_41_2F87C(static_cast<char*>(self) + 0x1700, destroy);
        fn_41_2F810(static_cast<char*>(self) + 0x1698, destroy);
        fn_41_2F79C(static_cast<char*>(self) + 0x1654, destroy);
        fn_41_2F740(static_cast<char*>(self) + 0x162C, destroy);
        fn_41_2F6CC(static_cast<char*>(self) + 0x14D0, destroy);
        fn_41_2F654(static_cast<char*>(self) + 0x12D8, destroy);
        fn_41_2F5D0(static_cast<char*>(self) + 0x10C8, destroy);
        fn_41_2F54C(static_cast<char*>(self) + 0xD6C, destroy);
        fn_41_2F488(static_cast<char*>(self) + 0xD08, destroy);
        fn_41_2F3D4(static_cast<char*>(self) + 0xCCC, destroy);
        fn_41_2F368(static_cast<char*>(self) + 0xC24, destroy);
        fn_41_2F2F4(static_cast<char*>(self) + 0xB10, destroy);
        fn_41_2F264(static_cast<char*>(self) + 0x878, destroy);
        fn_41_2F000(static_cast<char*>(self) + 0x654, destroy);
        fn_41_2EF2C(static_cast<char*>(self) + 0x624, destroy);
        fn_41_2EECC(static_cast<char*>(self) + 0x614, destroy);
        fn_41_2EDD4(static_cast<char*>(self) + 0x5FC, destroy);
        __dt__16soModuleAccesserFv(static_cast<char*>(self) + 0x51C, destroy);
        fn_41_2ECE4(self, destroy);
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
