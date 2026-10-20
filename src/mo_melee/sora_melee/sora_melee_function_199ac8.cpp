#include <types.h>
#pragma force_active on

struct FieldWord {
    unsigned int field : 5;
    unsigned int rest : 27;
};

extern "C" void fn_27_199AC8(void* self, unsigned int value) {
    reinterpret_cast<FieldWord*>(reinterpret_cast<u8*>(self) + 8)->field = value;
}
