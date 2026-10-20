#pragma force_active on
typedef unsigned char u8;

struct Vec {
    float x, y, z;
};

struct Stage {
    u8 pad0[0xBC];
    Vec* points;
    u8 index;
    u8 pad1[0x1EC - 0xC1];
    float lower;
    u8 pad2[8];
    float upper;
    u8 pad3[0x30A - 0x1FC];
    u8 state;
    u8 flags[4];

    int pairIndex() const { return index * 2; }
};

extern "C" {
extern const float lbl_48_rodata_4;
extern void* g_ftManager;
void fn_27_10D4A4(void*, int);

void fn_48_E6C(Stage* s) {
    switch (s->state) {
    case 0:
        if (s->flags[s->index] == 0) {
            int i = s->index * 2;
            float x = s->lower - lbl_48_rodata_4;
            if (s->points[i].x < x && s->points[i + 1].x < x) {
                s->flags[s->index] = 1;
                ++s->index;
                if (s->index >= 4)
                    s->index = 0;
                ++s->state;
            }
        }
        break;

    case 1: {
        int i = s->pairIndex();
        float x = lbl_48_rodata_4 + s->upper;
        if (s->points[i].x < x || s->points[i + 1].x < x) {
            fn_27_10D4A4(g_ftManager, s->index);
            s->state = 0;
        }
        break;
    }
    }

    if (s->flags[0] == 1 &&
        s->points[0].x > s->upper &&
        s->points[1].x > s->upper)
        s->flags[0] = 0;

    if (s->flags[1] == 1 &&
        s->points[2].x > s->upper &&
        s->points[3].x > s->upper)
        s->flags[1] = 0;

    if (s->flags[2] == 1 &&
        s->points[4].x > s->upper &&
        s->points[5].x > s->upper)
        s->flags[2] = 0;

    if (s->flags[3] == 1 &&
        s->points[6].x > s->upper &&
        s->points[7].x > s->upper)
        s->flags[3] = 0;
}
}
