#include <types.h>
#pragma force_active on

extern "C" {

void fn_8004DA50(void*);
void* fn_8004DA80(void*, int);
void fn_800485A4(void*);
void* getInstance__11ipPadConfigFv();
void fn_8004A2C8(void*, int, unsigned int, void*);
void fn_8004A5D8(void*);
extern void* g_GameGlobal;

struct PadElem {
    unsigned char pad0[7];
    unsigned char flag;     // 0x07
    unsigned char pad1[0x10];
    unsigned char charId;   // 0x18
    unsigned char pad2[0x24];
    unsigned char count;    // 0x3D
    unsigned char pad3[0x1E];
};

void fn_801104C4(void* arg0) {
    unsigned char sp8[0x2D];
    PadElem* p;
    int i;
    int val;
    void* src;

    fn_8004DA50(sp8);
    fn_800485A4(getInstance__11ipPadConfigFv());

    p = (PadElem*)((unsigned char*)arg0 + 0x98);

    for (i = 0; i < 4; i++) {
        if (p->flag == 0) {
            val = -1;
        } else {
            val = p->count - 1;
            if (val < 0) {
                val = i | 0x10;
            }
        }

        if (p->charId != 0x78) {
            src = fn_8004DA80(g_GameGlobal, p->charId);
        } else {
            src = sp8;
        }

        fn_8004A2C8(getInstance__11ipPadConfigFv(), i, (unsigned int)val, src);
        p++;
    }

    fn_8004A5D8(getInstance__11ipPadConfigFv());
}

}