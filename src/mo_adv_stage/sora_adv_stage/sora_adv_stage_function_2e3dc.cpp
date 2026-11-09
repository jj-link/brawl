#include <cstdio>

#pragma force_active on
#pragma readonly_strings on

struct Vec2 {
    float x;
    float y;
};

struct Entry {
    Vec2 a;
    Vec2 b;
    Vec2 c;
};

struct Object {
    char pad[0x150];
    unsigned short max;
    unsigned short count;
    Entry* entries;
};

extern "C" bool fn_40_19BE8(void*, float*, const char*);
extern const char lbl_40_data_B9C8[];

extern "C" void fn_40_2E3DC(Object* self) {
    Entry entry;
    float pos[3];
    char buf[16];

    self->count = 0;
    for (unsigned int i = 1; i <= 20; ++i) {
        std::sprintf(buf, lbl_40_data_B9C8, "AdvRebirth", i, "P");
        if (fn_40_19BE8(self, pos, buf)) {
            entry.a.x = pos[0];
            entry.a.y = pos[1];
            std::sprintf(buf, lbl_40_data_B9C8, "AdvRebirth", i, "TL");
            if (fn_40_19BE8(self, pos, buf)) {
                entry.b.x = pos[0];
                entry.b.y = pos[1];
                std::sprintf(buf, lbl_40_data_B9C8, "AdvRebirth", i, "BR");
                if (fn_40_19BE8(self, pos, buf)) {
                    entry.c.x = pos[0];
                    entry.c.y = pos[1];
                    if (self->count < self->max) {
                        self->entries[self->count] = entry;
                        ++self->count;
                    }
                }
            }
        }
    }
}
