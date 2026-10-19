#include <types.h>
#pragma force_active on

extern "C" void* fn_104_C020(char* p, int i);
extern "C" void* fn_104_BFE8(char* base, int kind);
extern "C" void* fn_104_BFD0(void* object, int index);
extern "C" void* fn_104_BFB8(void* object, int index);
extern "C" int fn_27_8D3E4(void* object);

extern "C" void fn_104_BE34(void* object) {
    for (int i = 0; i < 3; ++i) {
        void* member = fn_104_C020(static_cast<char*>(object) + 0x9be0, i);
        if (fn_27_8D3E4(static_cast<char*>(member) + 0x88) == 0) {
            return;
        }
    }
    for (int i = 0; i < 3; ++i) {
        void* member = fn_104_BFE8(static_cast<char*>(object) + 0x3e7c, i);
        if (fn_27_8D3E4(static_cast<char*>(member) + 0x88) == 0) {
            return;
        }
    }
    for (int i = 0; i < 1; ++i) {
        void* member = fn_104_BFD0(static_cast<char*>(object) + 0x1f48, i);
        if (fn_27_8D3E4(static_cast<char*>(member) + 0x88) == 0) {
            return;
        }
    }
    for (int i = 0; i < 1; ++i) {
        void* member = fn_104_BFB8(static_cast<char*>(object) + 0x0c, i);
        if (fn_27_8D3E4(static_cast<char*>(member) + 0x88) == 0) {
            return;
        }
    }
}
