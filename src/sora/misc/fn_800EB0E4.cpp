#pragma force_active on

extern "C" int getBGMId__9sndSystemFv(void*);
extern "C" int fn_80077DA0(void*, int);
extern "C" void playBGM__9sndSystemFiUlb(void*, int, unsigned long, int);
extern "C" void playSE__9sndSystemF5SndIDiiii(void*, int, int, int, int, int);

struct Tbl51 { int v[51]; };
struct Tbl3 { int v[3]; };

extern void* g_GameGlobal;
extern void* g_sndSystem;
extern Tbl51 lbl_80408A44;
extern Tbl3 lbl_80408B10;

extern "C" void fn_800EB0E4(char* arg0) {
    int st;
    char* r31 = *(char**)((char*)g_GameGlobal + 0x18);

    if (*(int*)(arg0 + 0x40) >= 2 &&
        getBGMId__9sndSystemFv(g_sndSystem) == -1 &&
        (*(int*)(arg0 + 0xD8) < 0 ||
         fn_80077DA0(g_sndSystem, *(int*)(arg0 + 0xD8)) == 0) &&
        *(unsigned char*)(r31 + 0x1378) != 9) {
        playBGM__9sndSystemFiUlb(g_sndSystem, 0x2700, 0, 1);
    }

    st = *(int*)(arg0 + 0xE4);
    if (st == 0 || st == 2) {
        if (*(unsigned int*)(arg0 + 0xE0) == 0x1E) {
            if (st == 0) {
                playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x2045, -1, 0, 0, -1);
            } else {
                playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x2041, -1, 0, 0, -1);
            }
        }

        if (*(unsigned int*)(arg0 + 0xE0) == 0x5A &&
            *(int*)(arg0 + 0xE4) == 2) {
            playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x20, -1, 0, 0, -1);
        }

        *(unsigned int*)(arg0 + 0xE0) =
            *(unsigned int*)(arg0 + 0xE0) + 1;
    }

    if (*(int*)(arg0 + 0xE4) == 0) {
        if (*(unsigned int*)(arg0 + 0xDC) >= 0x96) {
            *(int*)(arg0 + 0xE4) = 1;

            if (*(unsigned char*)(r31 + 2) == 0) {
                Tbl51 tbl = lbl_80408A44;
                playSE__9sndSystemF5SndIDiiii(
                    g_sndSystem,
                    tbl.v[*(unsigned char*)(r31 +
                        *(int*)(arg0 + 0xB8) * 0x2AC + 0x24)],
                    -1, 0, 0, -1);
            } else {
                Tbl3 se = lbl_80408B10;
                playSE__9sndSystemF5SndIDiiii(
                    g_sndSystem, se.v[*(int*)(arg0 + 0xBC)],
                    -1, 0, 0, -1);
            }
        }

        *(unsigned int*)(arg0 + 0xDC) =
            *(unsigned int*)(arg0 + 0xDC) + 1;
    }
}
