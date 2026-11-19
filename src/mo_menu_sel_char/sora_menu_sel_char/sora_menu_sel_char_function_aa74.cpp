#include <gm/gm_global.h>
#include <mu/wifi/mu_wifi_interface.h>
#pragma force_active on

extern "C" {
int fn_800CA6D4(void*, int);

static inline int mode(int s) {
    int r;
    if (s >= 0 && s < 4) r = 1; else r = 0;
    if (r != 0) return 0;
    if (s >= 4 && s < 0xc) r = 1; else r = 0;
    if (r != 0) return 1;
    int q;
    if (s >= 0xc && s < 0x10) q = 1; else q = 0;
    r = 3;
    if (q != 0) r = 2;
    return r;
}

int fn_10_AA74(void* self) {
    char* base = (char*)self;
    int state = ((unsigned char*)g_GameGlobal->m_selCharData)[4];
    if (mode(state) == 0) {
        int n = *(int*)(base + 0x648);
        int c = 0;
        for (int i = 0; i < n; i++) {
            char* p = ((char**)base)[i + 0x11];
            if (*(int*)(p + 0x1b4) != 0) c++;
        }
        if (c < 2) return 0;
    } else {
        if (*(int*)(*(char**)(base + 0x44) + 0x1b4) == 0) return 0;
    }
    char* c1 = base;
    char* p1;
    int n = *(int*)(base + 0x648);
    for (int i = 0; i < n; i++, c1 += 4) {
        p1 = *(char**)(c1 + 0x44);
        if (*(int*)(p1 + 0x1dc) >= 0) {
            int v = *(int*)(*(char**)(p1 + 0x1a8) + 0xa4);
            if (v != 0 && v != 3) return 0;
        }
    }
    {
        char* c = base;
        char* p;
        for (int i = 0; i < n; i++, c += 4) {
            p = *(char**)(c + 0x44);
            if (*(int*)(p + 0x1ac) != 0 && *(int*)(p + 0x1b4) != 0 && *(int*)p != 2 && *(int*)(*(char**)(p + 0x1a8) + 0xa0) != 0) return 0;
        }
    }
    {
        char* p;
        char* c = base;
        for (int i = 0; i < n; i++, c += 4) {
            p = *(char**)(c + 0x44);
            if (*(int*)p == 0 && *(int*)(p + 0x1b4) != 0 && *(int*)(p + 0x1b8) == 0x28) return 0;
        }
    }
    if (*(unsigned char*)(base + 0x5c8) != 0) {
        int f;
        if (mode(state) == 0 || mode(state) == 1)
            f = 0;
        else
            f = 1;
        if (f == 0) {
            int cnt[3] = {0, 0, 0};
            char* cursor = base;
            for (int i = 0; i < *(int*)(base + 0x648); cursor += 4, i++) {
                char* p = *(char**)(cursor + 0x44);
                if (*(int*)p == 1) {
                    int t = fn_800CA6D4(g_muWifiInterfaceTask, i);
                    if (t >= 0 && t < 3) cnt[t]++;
                } else if (*(int*)(p + 0x1b4) != 0) {
                    cnt[*(int*)(p + 0x1c0)]++;
                }
            }
            int k = 0;
            if (cnt[0] > 0) k = 1;
            if (cnt[1] > 0) k++;
            if (cnt[2] > 0) k++;
            if (k <= 1) return 0;
        }
    }
    return 1;
}
}
