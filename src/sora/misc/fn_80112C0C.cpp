#include <types.h>
#pragma force_active on

extern "C" {

void fn_80110A40(void* p);
extern u8 g_grCollisionList[];

void fn_80112C0C(u8* arg0) {
    u8* node;
    u8* end;

    if (((arg0[0x40] >> 6) & 1) && arg0[0x41] == 0) {
        end = g_grCollisionList + 4;
        node = *(u8**)end;
        while (node != end) {
            if (((node[-4] >> 5) & 1)) {
                fn_80110A40(node - 0x30);
                node[-4] = node[-4] & ~0x20;
            }
            node = *(u8**)node;
        }
    }
}

}
