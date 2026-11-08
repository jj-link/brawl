#include <if/if_mngr.h>
#include <if/if_adv_mngr.h>
#pragma force_active on

struct Data { int kind; float value; int c, d, e; };
struct Self { char pad[4]; unsigned char first, second; };
struct Params {
    int a, b, id;
    unsigned char player, d;
    signed char e;
    unsigned char pad;
    int f;
    unsigned int value;
    unsigned char enabled;
    char pad2[3];
    int mode, j;
    unsigned char k, l;
    char pad3[2];
    int m, n, o, p, q;
    unsigned char r;
    char pad4[3];
    int s;
};
extern "C" {
void fn_80107848(IfAdvMngr*, const Data*);
void fn_80107900(IfAdvMngr*, unsigned char);
void fn_800DCEA8(IfMngr*, const Data*);
void fn_800DCF60(IfMngr*, unsigned char);
void fn_800E08A0(void*, Params*, unsigned char);
void fn_800E14A4(void*, unsigned int, int);
}
extern float lbl_40_rodata_220, lbl_40_rodata_224;

extern "C" void fn_40_156DC(Self* self, const Data* input, int flag) {
    if (g_IfAdvMngr) {
        Data copy = *input;
        fn_80107848(g_IfAdvMngr, &copy);
        fn_80107900(g_IfAdvMngr, 1);
    }
    IfMngr* manager = g_IfMngr;
    if (manager) {
        if (!flag) {
            Data copy = *input;
            fn_800DCEA8(manager, &copy);
            fn_800DCF60(g_IfMngr, 1);
        } else {
            Params p;
            p.a = 0;
            p.id = 0;
            p.player = 0;
            p.d = 0;
            p.e = -1;
            p.f = 0;
            p.value = 0;
            p.enabled = 0;
            p.mode = 3;
            p.j = 0;
            p.k = 0;
            p.l = 0;
            p.m = 0;
            p.r = 1;
            p.s = 0;
            p.n = 0;
            p.o = 0;
            p.p = 0;
            p.q = 0;
            p.b = 1;
            bool small = input->value > lbl_40_rodata_220 && input->value < lbl_40_rodata_224;
            p.value = small ? 1 : (unsigned int)input->value;
            p.enabled = 1;
            if (input->kind == 0 && !self->first) {
                p.id = 60;
                p.player = 1;
                p.mode = 0;
                fn_800E08A0(g_IfMngr->m_ifPlayers[1], &p, *((unsigned char*)g_IfMngr + 0xa8));
                self->first = 1;
            } else if (input->kind == 0 && manager->m_ifPlayers[1]) {
                fn_800E14A4(g_IfMngr->m_ifPlayers[*((unsigned char*)g_IfMngr + 0x69)], p.value, 0);
            }
            if (input->kind == 1 && !self->second) {
                p.id = 61;
                p.player = 2;
                p.mode = 0;
                fn_800E08A0(g_IfMngr->m_ifPlayers[2], &p, *((unsigned char*)g_IfMngr + 0xa8));
                self->second = 1;
            } else if (input->kind == 1 && g_IfMngr->m_ifPlayers[2]) {
                fn_800E14A4(g_IfMngr->m_ifPlayers[*((unsigned char*)g_IfMngr + 0x6a)], p.value, 0);
            }
        }
    }
}