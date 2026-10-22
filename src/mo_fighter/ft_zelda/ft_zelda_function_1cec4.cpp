#include <types.h>
#pragma force_active on

extern "C" void* fn_104_1D0DC(void* object, int index);
extern "C" void* fn_104_1D0C4(void* object, int index);
extern "C" void* fn_104_1D0AC(void* object, int index);
extern "C" void* fn_104_1D094(void* object, int index);
extern "C" void* fn_104_1D07C(void* object, int index);
extern "C" void* fn_104_1D064(void* object, int index);
extern "C" int fn_27_8D3E4(void* object);

extern "C" void fn_104_1CEC4(void* object) {
    for (int i = 0; i < 8; ++i) {
        void* member = fn_104_1D0DC(static_cast<char*>(object) + 0x96fc, i);
        if (fn_27_8D3E4(static_cast<char*>(member) + 0x88) == 0) {
            return;
        }
    }
    for (int i = 0; i < 1; ++i) {
        void* member = fn_104_1D0C4(static_cast<char*>(object) + 0x7efc, i);
        if (fn_27_8D3E4(static_cast<char*>(member) + 0x88) == 0) {
            return;
        }
    }
    for (int i = 0; i < 1; ++i) {
        void* member = fn_104_1D0AC(static_cast<char*>(object) + 0x5dc8, i);
        if (fn_27_8D3E4(static_cast<char*>(member) + 0x88) == 0) {
            return;
        }
    }
    for (int i = 0; i < 1; ++i) {
        void* member = fn_104_1D094(static_cast<char*>(object) + 0x3e7c, i);
        if (fn_27_8D3E4(static_cast<char*>(member) + 0x88) == 0) {
            return;
        }
    }
    for (int i = 0; i < 1; ++i) {
        void* member = fn_104_1D07C(static_cast<char*>(object) + 0x1f48, i);
        if (fn_27_8D3E4(static_cast<char*>(member) + 0x88) == 0) {
            return;
        }
    }
    for (int i = 0; i < 1; ++i) {
        void* member = fn_104_1D064(static_cast<char*>(object) + 0x0c, i);
        if (fn_27_8D3E4(static_cast<char*>(member) + 0x88) == 0) {
            return;
        }
    }
}
