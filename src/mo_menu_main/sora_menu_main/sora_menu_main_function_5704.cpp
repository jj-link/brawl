#include <snd/snd_system.h>
#pragma force_active on
struct FigListMenu {
    char pad[0x13c];
    unsigned int count;
    unsigned int cursor;
};
extern "C" int fn_2_5838(FigListMenu*, int, int);
extern "C" int fn_2_5B90(FigListMenu*, int, int);
extern "C" int fn_2_5704(FigListMenu* self, int direction, int execute) {
    unsigned int current = self->cursor;
    unsigned int next = current;
    switch (direction) {
    case 0:
        if (current >= 3) next = current - 3;
        break;
    case 1:
        if (self->count - 1 - current >= 3) next = current + 3;
        break;
    case 2:
        if (current % 3 != 0) next = current - 1;
        else return fn_2_5B90(self, execute, 0);
        break;
    case 3:
        if (current % 3 != 2 && current != self->count - 1) next = current + 1;
        else return fn_2_5838(self, execute, 0);
        break;
    }
    if (next != current) {
        if (execute) {
            self->cursor = next;
            g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
        }
        return 1;
    }
    return 0;
}