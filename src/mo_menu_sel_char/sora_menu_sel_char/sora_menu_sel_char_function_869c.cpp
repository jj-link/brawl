#include <snd/snd_system.h>
#pragma force_active on
extern "C" {
void fn_10_17C18(void*);
int fn_10_DA54(void*, int);
void fn_10_D540(void*, int, int);
void fn_10_1C330(int);
int fn_10_12010(void*, int);
int exchangeSelchkind2SelCharNarrationSndID__6muMenuFiii(int);
int exchangeMuSelchkind2MuStockchkind__6muMenuFiii(int);
int fn_10_14618(void*);
void fn_80077B98(sndSystem*, int, int, int, int);
void fn_10_87CC(void*, int);
void fn_10_13CAC(void*);
}
extern "C" void fn_10_869C(void* self, int index, int kind) {
    char* area = ((char**)((char*)self + 0x44))[index];
    int object = *(int*)(area + 0x1ac);
    fn_10_17C18(area);
    fn_10_D540(self, fn_10_DA54(self, kind), 2);
    fn_10_1C330(object);
    if (kind != 0x29) {
        g_sndSystem->playSE((SndID)exchangeSelchkind2SelCharNarrationSndID__6muMenuFiii(fn_10_12010(area, *(int*)(area + 0x1b8))), -1, 0, 0, -1);
    }
    if (*(int*)(area + 0x1b4) == 1 && kind != 0x29) {
        object = *(int*)(area + 0x1dc);
        if (object >= 0) {
            int state = fn_10_14618(area);
            if (state != 0 && state != 4) {
                int stock = exchangeMuSelchkind2MuStockchkind__6muMenuFiii(fn_10_12010(area, *(int*)(area + 0x1b8)));
                if ((unsigned int)(stock + 0x10000) != 0xffff) {
                    fn_80077B98(g_sndSystem, object - 4, stock, -1, 0);
                }
            }
        }
    }
    fn_10_87CC(self, index);
    fn_10_13CAC(area);
}