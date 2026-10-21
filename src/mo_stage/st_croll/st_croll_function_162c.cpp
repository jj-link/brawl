#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

struct _GXColor {
    u8 r, g, b, a;
};

class efScreen {
public:
    u32 requestFill(float, s32, s32, _GXColor*);
};

extern "C" {
extern efScreen* g_efScreen;
extern const float lbl_90_rodata_4;

void fn_8005E3C8(efScreen*, const u8*, float);

struct FillObj {
    char pad[0x1fc];
    u8 m_alpha;
    char pad2[7];
    s32 m_state;
};

void fn_90_162C(FillObj* self, s32 arg1) {
    s32 state = arg1;
    if (state != 0) {
        state = 1;
    }
    if (self->m_state != state) {
        self->m_state = state;
        if (state == 0) {
            u8 alpha = self->m_alpha;
            fn_8005E3C8(g_efScreen, &alpha, lbl_90_rodata_4);
        } else {
            u8 c[4];
            u32 col;
            c[2] = 0;
            c[1] = 0;
            c[0] = 0;
            c[3] = 0x80;
            col = *(u32*)c;
            self->m_alpha = (u8)(g_efScreen->requestFill(lbl_90_rodata_4, 4, 0x80, (_GXColor*)&col) >> 24);
        }
    }
}
}
