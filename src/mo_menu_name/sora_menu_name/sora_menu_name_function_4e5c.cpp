#pragma force_active on
struct Vec2 { float x, y; Vec2() {} Vec2(const Vec2& o) { x = o.x; y = o.y; } };
struct PadStatus {
    int w[6];
    Vec2 v[3];
    unsigned char b0, b1, b2, b3, b4, b5, b6, b7, b8;
    int last;
};
struct Raw { int w[16]; };
extern "C" {
extern void* g_gfPadSystem;
extern void* g_sndSystem;
void fn_8002B504(void*);
int fn_8021A024(int, void*);
void getSysPadStatus__11gfPadSystemFiP11gfPadStatus(void*, int, Raw*);
void playSE__9sndSystemF5SndIDiiii(void*, int, int, int, int, int);
}

inline Raw getRaw() {
    Raw s;
    getSysPadStatus__11gfPadSystemFiP11gfPadStatus(g_gfPadSystem, 0xf0, &s);
    return s;
}

extern "C" int fn_16_4E5C(char* self) {
    int done = 0;
    if (*(int*)(self + 0x3f0) > 0) {
        if (--*(int*)(self + 0x3f0) == 0)
            fn_8002B504(g_gfPadSystem);
        return *(int*)(self + 0x9c);
    }
    int i;
    char buf[8];
    for (i = 0; i < 4; i++) {
        if (fn_8021A024(i, buf) == 0)
            break;
    }
    if (i >= 4) {
        PadStatus b(*(PadStatus*)&getRaw());
        if ((b.w[3] & 0x1000) || (b.w[3] & 0x200)) {
            playSE__9sndSystemF5SndIDiiii(g_sndSystem, 2, -1, 0, 0, -1);
            done = 1;
        }
    } else {
        *(int*)(self + 0x400) = i;
        done = 1;
        *(int*)(*(char**)(self + 0x408) + 0x40) = i;
    }
    if (done)
        return 10;
    return *(int*)(self + 0x9c);
}
