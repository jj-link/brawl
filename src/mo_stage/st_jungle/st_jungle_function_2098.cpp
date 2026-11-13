#pragma force_active on

struct Vec {
    float x, y, z;
};

struct Stage {
    unsigned char pad0[0xBC];
    Vec* points;
    unsigned char index;
    unsigned char pad1[0x1DC - 0xC1];
    float lower;
    unsigned char pad2[8];
    float upper;
    unsigned char pad3[0x44E - 0x1EC];
    unsigned char state;
    unsigned char flags[4];

    int pairIndex() const { return index * 2; }
};

extern "C" {
extern const float lbl_51_rodata_8;
extern void* g_ftManager;
void fn_27_10D4A4(void*, int);

void fn_51_2098(Stage* s) {
    switch ((int)s->state) {
    case 0:
        s->index = 3;
        fn_27_10D4A4(g_ftManager, 3);
        ++s->state;
        break;
    case 1:
        if (s->flags[s->index] == 0) {
            int i = s->index * 2;
            if (s->points[i].y < s->upper - lbl_51_rodata_8 && s->points[i + 1].y < s->upper - lbl_51_rodata_8) {
                s->flags[s->index] = 1;
                ++s->index;
                if (s->index >= 4)
                    s->index = 0;
                s->state = 2;
            }
        }
        break;
    case 2: {
        int i = s->pairIndex();
        if (s->points[i].y < lbl_51_rodata_8 + s->lower || s->points[i + 1].y < lbl_51_rodata_8 + s->lower) {
            fn_27_10D4A4(g_ftManager, s->index);
            s->state = 1;
        }
        break;
    }
    }

    if (s->flags[0] == 1 &&
        s->points[0].y > s->lower &&
        s->points[1].y > s->lower)
        s->flags[0] = 0;

    if (s->flags[1] == 1 &&
        s->points[2].y > s->lower &&
        s->points[3].y > s->lower)
        s->flags[1] = 0;

    if (s->flags[2] == 1 &&
        s->points[4].y > s->lower &&
        s->points[5].y > s->lower)
        s->flags[2] = 0;

    if (s->flags[3] == 1 &&
        s->points[6].y > s->lower &&
        s->points[7].y > s->lower)
        s->flags[3] = 0;
}
}
