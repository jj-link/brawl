#include <types.h>

extern "C" void* fn_114_E918(void* object, int index);
extern "C" void* fn_114_E8F0(void* object, int index);
extern "C" void* fn_114_E8C4(void* object, int index);
extern "C" void* fn_114_E790(void* object, int index);
extern "C" void* fn_114_E778(void* object, int index);
extern "C" int fn_27_8D3E4(void* object);

extern "C" void fn_114_E5BC(void* object) {
    for (int i = 0; i < 1; ++i) {
        void* member = fn_114_E918(static_cast<char*>(object) + 0x3e6f8, i);
        if (fn_27_8D3E4(static_cast<char*>(member) + 0x88) == 0) {
            return;
        }
    }
    for (int i = 0; i < 2; ++i) {
        void* member = fn_114_E8F0(static_cast<char*>(object) + 0x39ed4, i);
        if (fn_27_8D3E4(static_cast<char*>(member) + 0x88) == 0) {
            return;
        }
    }
    for (int i = 0; i < 2; ++i) {
        void* member = fn_114_E8C4(static_cast<char*>(object) + 0x1e2a0, i);
        if (fn_27_8D3E4(static_cast<char*>(member) + 0x88) == 0) {
            return;
        }
    }
    for (int i = 0; i < 16; ++i) {
        void* member = fn_114_E790(static_cast<char*>(object) + 0x211c, i);
        if (fn_27_8D3E4(static_cast<char*>(member) + 0x88) == 0) {
            return;
        }
    }
    for (int i = 0; i < 1; ++i) {
        void* member = fn_114_E778(static_cast<char*>(object) + 0x0c, i);
        if (fn_27_8D3E4(static_cast<char*>(member) + 0x88) == 0) {
            return;
        }
    }
}
