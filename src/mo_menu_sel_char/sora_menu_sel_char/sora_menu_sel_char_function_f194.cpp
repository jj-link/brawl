#include <gm/gm_global.h>
#pragma force_active on
extern "C" {
int fn_800B61C0(void*);
int fn_800B5854(void*, int, int, int, int);
extern unsigned char lbl_10_rodata_4E8[];
void fn_10_F194(void* arg0) {
    if (*(int*)((char*)arg0 + 0x5e8) == 1) {
        void* p = *(void**)((char*)arg0 + 0x3c4);
        if (fn_800B61C0(p)) {
            *(int*)((char*)arg0 + 0x5e8) = 2;
            fn_800B5854(p, (*(unsigned char*)((char*)arg0 + 0x5ec) != 0) + 1, 0x11, 1, 0);
            void* q = *(void**)((char*)arg0 + 0x140);
            int state = ((unsigned char*)g_GameGlobal->m_selCharData)[4];
            int result;
            if (state >= 0 && state < 4) result = 1; else result = 0;
            if (result != 0) result = 0;
            else {
                if (state >= 4 && state < 0xc) result = 1; else result = 0;
                if (result != 0) result = 1;
                else {
                    int r;
                    if (state >= 0xc && state < 0x10) r = 1; else r = 0;
                    result = 3;
                    if (r != 0) result = 2;
                }
            }
            fn_800B5854(q, (result * 2 + lbl_10_rodata_4E8)[1], 0x18, 1, 0);
        }
    }
}
}