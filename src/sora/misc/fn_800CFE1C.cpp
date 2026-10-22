#pragma force_active on
#include <types.h>

extern "C" u8 fn_800C851C(void);
extern "C" void fn_800D0AE0(void*, void*);
extern "C" void fn_80145B98(int, int);
extern int lbl_805A03A8;

struct Entry {
    char pad[0xC6];
    u8 lo : 1;
    u8 mid : 1;
    u8 rest : 5;
    u8 x : 1;
    char pad2[3];
    u8 ca;
};

extern "C" void fn_800CFE1C(char* self) {
    u8 idx = fn_800C851C();
    if (idx == 0xFF) {
        idx = 4;
    }
    Entry* e1 = (Entry*)(self + idx * 0x218);
    e1->mid = 0;
    e1->ca = 0;

    u8 idx2 = fn_800C851C();
    if (idx2 == 0xFF) {
        idx2 = 4;
    }
    Entry* e2 = (Entry*)(self + idx2 * 0x218);
    e2->x = 1;

    fn_800D0AE0(self, (void*)e2);
    fn_80145B98(lbl_805A03A8, 0xFE);
}
