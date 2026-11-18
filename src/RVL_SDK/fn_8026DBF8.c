#include <types.h>
#pragma force_active on

typedef struct {
    unsigned char pad[0xAC];
    void (*a)(void);
    void (*b)(void);
} Object;

typedef struct {
    unsigned char pad[0x2E];
    unsigned char sel;
    unsigned char pad2;
    unsigned short x;
    unsigned short y;
    unsigned char pad3[0x14];
    unsigned int x4;
    unsigned int y4;
} Params;

extern void fn_8026DCEC(void);
extern void fn_8026E2B4(void);
extern void fn_8026DF60(void);
extern void fn_8026E4AC(void);
extern void fn_8026E104(void);
extern void fn_8026E6A8(void);

int fn_8026DBF8(Object *self, Params *p) {
    switch (p->sel) {
    case 0:
        self->a = fn_8026DCEC;
        self->b = fn_8026E2B4;
        break;
    case 1:
        self->a = fn_8026DF60;
        self->b = fn_8026E4AC;
        break;
    case 2:
        self->a = fn_8026E104;
        self->b = fn_8026E6A8;
        break;
    default:
        return -112;
    }

    {
        unsigned short w = p->x;
        unsigned short h = p->y;
        int hq = h / 4;
        int hr = (h % 4) != 0;
        p->x4 = ((w / 4) + ((w % 4) != 0)) * 4;
        p->y4 = hr;
        p->y4 = (hq + p->y4) * 4;
    }
    return 0;
}
