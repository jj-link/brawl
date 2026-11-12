#include <types.h>
#include <nw4r/ut/ut_algorithm.h>

#pragma force_active on

struct Point {
    float x, y;
};
struct Obj {
    char pad[0x52];
    short h;
};
struct Entry {
    Point pos;
    Obj* obj;
};
struct Mgr {
    int unk0;
    Entry entries[64];
    char pad[0x648 - 0x304];
    s8 orderX[64];
    s8 orderY[64];
};

extern "C" {
extern const float lbl_27_rodata_61E0;
extern const float lbl_27_rodata_626C;

void fn_27_2D5104(Mgr* self) {
    int j;
    int pos;
    int pos2;
    int i;
    Entry* e = self->entries;
    int count = 0;
    for (i = 0; i < 64; i++, e++) {
        if (e->obj != 0) {
            pos = 0;
            Point coords = { e->pos.x, e->pos.y };
            coords.y += (float)e->obj->h / lbl_27_rodata_626C;

            while (pos < count) {
                Point prev = self->entries[self->orderX[pos]].pos;
                prev.y += (float)self->entries[self->orderX[pos]].obj->h / lbl_27_rodata_626C;

                if (nw4r::ut::Abs(coords.x - prev.x) < lbl_27_rodata_61E0) {
                    if (coords.y > prev.y)
                        break;
                } else if (coords.x < prev.x) {
                    break;
                }
                pos++;
            }

            for (j = count; j > pos; j--) {
                self->orderX[j] = self->orderX[j - 1];
            }
            self->orderX[pos] = i;

            pos2 = 0;
            while (pos2 < count) {
                Point prev = self->entries[self->orderY[pos2]].pos;
                prev.y += (float)self->entries[self->orderY[pos2]].obj->h / lbl_27_rodata_626C;

                if (nw4r::ut::Abs(coords.y - prev.y) < lbl_27_rodata_61E0) {
                    if (coords.x < prev.x)
                        break;
                } else if (coords.y > prev.y) {
                    break;
                }
                pos2++;
            }

            for (j = count; j > pos2; j--) {
                self->orderY[j] = self->orderY[j - 1];
            }
            count++;
            self->orderY[pos2] = i;
        }
    }
}
}
