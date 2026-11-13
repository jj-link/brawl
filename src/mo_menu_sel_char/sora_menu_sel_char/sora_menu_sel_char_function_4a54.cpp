#pragma force_active on

extern "C" void fn_10_10ACC(void* self, int flag);
extern "C" void fn_10_19EF0(void* obj, int v);
extern "C" void fn_10_1C57C(void* obj, int v);
extern "C" void fn_10_1B828(void* p);
extern "C" void fn_10_B010(void* self, int v);
extern "C" int fn_10_B1CC(void* self);
extern "C" void fn_80073F84(void* snd, int v);
extern "C" int fn_800BF048(int, char*, unsigned long, void*, void*, int, int, int, int, int, int, int);
extern "C" void getPrintIndexData__7MessageFPvUlPPcPUl(void*, unsigned long, char**, unsigned long*);
extern char* g_GameGlobal;
extern void* g_sndSystem;

struct BF {
    unsigned char pad[0x2E];
    unsigned char hi : 3;
    unsigned char mid : 3;
    unsigned char lo : 2;
};

extern "C" void fn_10_4A54(char* self, int state, signed char flag, unsigned long arg3) {
    unsigned long len;
    char* text;

    *(int*)(self + 0x40) = state;
    switch (state) {
    case 1: {
        int v = 0;
        *(int*)(self + 0x5F8) = 2;
        switch (*(int*)(self + 0x650)) {
        case 0:
            v = 0;
            break;
        case 1:
            v = 1;
            break;
        case 2: {
            int b = *(unsigned char*)(*(char**)((char*)g_GameGlobal + 0x1C) + 7);
            if (b == 1 || b == 3) {
                v = 1;
            } else {
                v = 0;
            }
            break;
        }
        }
        if (v != 0) {
            fn_80073F84(g_sndSystem, 0);
        }
        break;
    }
    case 6: {
        unsigned long n;
        char* txt;
        getPrintIndexData__7MessageFPvUlPPcPUl(*(void**)(self + 0x610), 0x1A, &text, &len);
        n = len;
        txt = text;
        fn_10_B1CC(self);
        fn_10_10ACC(self, 0);
        *(int*)(self + 0x60C) = fn_800BF048(1, txt, n, *(void**)(self + 0x608), *(void**)(self + 0x6C), 0x74, 0x1E, 0x2A, 0x2A, 0, 0, 0xF0);
        {
            void** cur = (void**)self;
            for (int i = 0; i < *(int*)(self + 0x648); i++) {
                fn_10_19EF0(*(void**)((char*)cur[0x11] + 0x1A8), 1);
                fn_10_1C57C(*(void**)((char*)cur[0x11] + 0x1AC), 1);
                cur++;
            }
        }
        {
            void** cur = (void**)self;
            for (int i = 0; i < *(int*)(self + 0x648); i++) {
                fn_10_1B828(*(void**)((char*)cur[0x11] + 0x1A8));
                cur++;
            }
        }
        break;
    }
    case 8:
        fn_10_B010(self, arg3);
        break;
    }

    if ((unsigned)(state - 3) <= 1U) {
        char* g10 = *(char**)((char*)g_GameGlobal + 0x10);
        char* g1c = *(char**)((char*)g_GameGlobal + 0x1C);
        if (*(signed char*)(g10 + 4) == 4) {
            ((BF*)g10)->mid = *(int*)(self + 0x5DC);
        } else {
            int c = *(unsigned char*)(g1c + 2);
            if (c == 1) {
                *(signed char*)(g1c + 4) = (signed char)*(int*)(self + 0x5DC);
            } else {
                *(signed char*)(g1c + 3) = (signed char)*(int*)(self + 0x5D8);
            }
        }
    }
    if (state == 1 || (unsigned)(state - 3) <= 1U) {
        char* g10 = *(char**)((char*)g_GameGlobal + 0x10);
        *(signed char*)(g10 + 5) = flag;
    }
}
