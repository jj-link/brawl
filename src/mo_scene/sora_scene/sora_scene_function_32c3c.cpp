class gfSceneManager;

#pragma force_active on

extern "C" {
void* getInstance__14gfSceneManagerFv();
void* searchScene__14gfSceneManagerFPCc(gfSceneManager*, const char*);
void setNextScene__14gfSceneManagerFv(gfSceneManager*, const char*, int);
void setNextSequence__14gfSceneManagerFv(gfSceneManager*, const char*, int);
void* __dynamic_cast(void*, long, const void*, const void*, long);

unsigned int fn_1_331DC(void*);
void fn_1_33B24(void*);
void fn_1_33C08(void*);
void fn_1_33EDC();
void fn_1_3422C();
void fn_1_3D2D8();
int fn_80052DB0();
void fn_800532F0(unsigned int, int);
char* fn_8004E580(void*);
char* fn_8004E5F8(void*);
int fn_80055888(int, int);

extern char lbl_1_data_8000[];
extern char lbl_1_data_2158[];
extern char __RTTI__7gfScene[];
extern char* g_GameGlobal;
extern char* g_gfApplication;
extern int lbl_1_bss_1A60;
}

extern "C" void fn_1_32C3C(char* self) {
    const char* str = lbl_1_data_8000;
    gfSceneManager* mgr = (gfSceneManager*)getInstance__14gfSceneManagerFv();
    char* p;
    int count;
    unsigned char a;
    unsigned char b;
    int cont = 1;

    while (cont) {
        cont = 0;
        switch (*(unsigned int*)(self + 8)) {
        default:
            *(int*)(self + 8) = 0;
        case 0:
            g_gfApplication[0x110] = 0;
            *(int*)(self + 0x14) = 0;
            *(int*)(self + 8) = 1;
            *(int*)(self + 0xc) = 3;
            self[0x10] = 13;
            cont = 1;
            break;

        case 1:
            setNextScene__14gfSceneManagerFv(
                mgr, str + 0x70, *(unsigned char*)(self + 0x10));
            *(int*)(self + 8) = 2;
            break;

        case 2:
            cont = 1;
            *(int*)(self + 8) = *(int*)(self + 0xc);
            break;

        case 3: {
            setNextScene__14gfSceneManagerFv(
                mgr, str + 0x80, *(int*)(self + 0x14));
            char* p = *(char**)(g_GameGlobal + 0x10);
            int n = fn_80052DB0();
            p[4] = 11;
            p[0] = n + 1;
            char* scene = (char*)__dynamic_cast(
                searchScene__14gfSceneManagerFPCc(mgr, str + 0x80),
                4, lbl_1_data_2158, __RTTI__7gfScene, 0);
            *(int*)(scene + 0x394) = n;
            *(int*)(self + 8) = 4;
            break;
        }

        case 4:
            switch (*(int*)((char*)mgr + 0x284)) {
            case 1:
                if (fn_1_331DC(self) == 1) {
                    *(int*)(self + 8) = 1;
                    *(int*)(self + 0xc) = 5;
                    self[0x10] = 13;
                } else {
                    fn_1_33C08(self);
                    *(int*)(self + 8) = 1;
                    *(int*)(self + 0xc) = 7;
                    self[0x10] = 0;
                }
                break;
            case 0:
                *(int*)(self + 8) = 11;
                break;
            }
            cont = 1;
            *(int*)(self + 0x24) = fn_80052DB0();
            break;

        case 5: {
            fn_1_3D2D8();
            p = *(char**)(g_GameGlobal + 0x10);
            char* scene = (char*)__dynamic_cast(
                searchScene__14gfSceneManagerFPCc(mgr, str + 0x80),
                4, lbl_1_data_2158, __RTTI__7gfScene, 0);
            count = *(int*)(scene + 0x368);
            a = *(int*)(scene + 0x36c);
            if (count == 2)
                b = *(int*)(scene + 0x370);
            setNextScene__14gfSceneManagerFv(mgr, str + 0x8c, 0);
            p[4] = 11;
            p[0] = a + 1;
            p[8] = 1;
            p[0xbf] = a + 1;
            if (count == 2)
                p[0x11b] = b + 1;
            else
                p[0x11b] = 0;
            *(int*)(self + 8) = 6;
            break;
        }

        case 6: {
            char* p;
            char* scene = (char*)__dynamic_cast(
                searchScene__14gfSceneManagerFPCc(mgr, str + 0x80),
                4, lbl_1_data_2158, __RTTI__7gfScene, 0);
            p = *(char**)(g_GameGlobal + 0x10);
            switch (*(int*)((char*)mgr + 0x284)) {
            case 0:
                *(int*)(self + 0x14) = 1;
                *(int*)(self + 8) = 3;
                break;
            case 1:
                fn_1_33B24(self);
                fn_1_33C08(self);
                *(int*)(self + 8) = 1;
                *(int*)(self + 0xc) = 7;
                self[0x10] = 0;
                {
                    char* dst = scene;
                    for (int i = 0; i < *(int*)(scene + 0x368); i++) {
                        int n = *(unsigned char*)(p + 0xd0);
                        if (n == 0x78)
                            n = -1;
                        *(int*)(dst + 0x374) = n;
                        p += 0x5c;
                        dst += 4;
                    }
                }
                break;
            }
            cont = 1;
            break;
        }

        case 7:
            g_gfApplication[0x110] = self[0x18];
            setNextScene__14gfSceneManagerFv(mgr, str + 0xa0, 0);
            *(int*)(self + 8) = 8;
            break;

        case 8: {
            g_gfApplication[0x110] = 0;
            fn_1_3422C();
            fn_800532F0(
                *(unsigned int*)(*(char**)(g_GameGlobal + 0x18) + 0x1384) / 60,
                lbl_1_bss_1A60);
            unsigned int flag;
            if (!(*(int*)(fn_8004E580(g_GameGlobal) + 4) & 4) &&
                fn_80055888(1, 0) >= 20 &&
                ((*(unsigned int*)(fn_8004E5F8(g_GameGlobal) + 0x10) >> 26) & 1) == 1) {
                *(int*)(fn_8004E580(g_GameGlobal) + 4) |= 2;
                flag = 1;
            } else {
                flag = 0;
            }
            if (flag == 1)
                fn_1_33EDC();
            cont = 1;
            *(int*)(self + 8) = 9;
            break;
        }

        case 9:
            setNextSequence__14gfSceneManagerFv(mgr, str + 0xa8, 10);
            break;

        case 10: {
            *(int*)(*(char**)(g_GameGlobal + 0x1c) + 0x24) =
                *(int*)(self + 0x24);
            *(int*)(self + 0x14) = 1;
            *(int*)(self + 8) = 1;
            *(int*)(self + 0xc) = 3;
            self[0x10] = 13;
            unsigned char f = g_gfApplication[0xcc];
            unsigned int high = (f >> 7) & 1;
            unsigned int low = (f >> 6) & 1;
            if (!high && !low)
                g_gfApplication[0xcc] = f | 0xc0;
            cont = 1;
            break;
        }

        case 11:
            g_gfApplication[0x110] = self[0x18];
            setNextSequence__14gfSceneManagerFv(mgr, str + 0xb8, 8);
            *(int*)(self + 8) = 12;
            break;
        }
    }
}
