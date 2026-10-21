#include <types.h>
#pragma force_active on

extern "C" void* fn_80158BE0();
extern "C" void fn_80159024(void*, void*, int);
extern "C" void fn_801590A0(void*, void*, int);

struct Item {
    Item* next;      // 0x00
    u8 pad04[8];     // 0x04
    void* data;      // 0x0C
    u8 flag;         // 0x10
    u8 pad11[0x2C - 0x11];
    u8 state;        // 0x2C
};

struct Owner {
    u8 pad00[0x40];
    Item* list;      // 0x40
};

extern "C" {
void fn_27_232F7C(Owner* self, int arg) {
    Item* it = self->list;
    while (it != nullptr) {
        if (it->state == 1) {
            if (it->flag == 1 && arg != 0) {
                fn_80159024(fn_80158BE0(), it->data, 1);
            } else if (it->flag == 2) {
                fn_801590A0(fn_80158BE0(), it->data, 1);
            }
        }
        it = it->next;
    }
}
}
