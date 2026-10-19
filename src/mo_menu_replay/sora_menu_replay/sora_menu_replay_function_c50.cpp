#pragma force_active on
extern "C" {
void fn_1_379C(int idx, int a, int b);
int fn_1_385C(int v);
int fn_800C39D8(void* p);
void* getInstance__14gfSceneManagerFv();
extern void* g_GameGlobal;
}

extern "C" void fn_7_C50(void* self) {
    char* a = *(char**)((char*)self + 0x1ac);
    char* p;
    if (*(int*)(a + 0x1d10) == 0 && *(unsigned char*)(a + 0x1d18) == 0) {
        *(unsigned char*)(a + 0x1d18) = 1;
        p = *(char**)((char*)g_GameGlobal + 0x8);
        for (int i = 0; i < 4; i++, p += 0x5c) {
            int t = *(unsigned char*)(p + 0x99);
            if (t != 0 && t != 1) {
                continue;
            }
            int v = *(unsigned char*)(p + 0x98);
            if (!(v < 0 && v >= 0x3e)) {
                fn_1_379C(i, v, *(unsigned char*)(p + 0x9d));
            }
        }
    }

    a = *(char**)((char*)self + 0x1ac);
    if (*(int*)(a + 0x1d14) > 0) {
        (*(int*)(a + 0x1d14))--;
    } else if (fn_1_385C(0)) {
        if (fn_800C39D8(*(void**)(*(char**)((char*)self + 0x1ac) + 0x1ce4))) {
            p = *(char**)(*(char**)((char*)self + 0x1ac) + 0x1d10);
            char* mgr = (char*)getInstance__14gfSceneManagerFv();
            *(char**)(mgr + 0x284) = p;
            *(int*)(mgr + 0x288) = 2;
        }
    }
}
