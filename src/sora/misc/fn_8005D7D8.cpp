#include <types.h>
#pragma force_active on

struct Color {
    unsigned char r, g, b, a;
    Color() {}
    Color(const Color& other) : r(other.r), g(other.g), b(other.b), a(other.a) {}
};
struct gfCameraController_base { unsigned char id; char pad[3]; };
class gfCameraController : public gfCameraController_base {
public:
    virtual void slot0(int, Color);
};
struct Group { unsigned char count; signed char slots[16]; };
struct Data {
    unsigned char flag;
    char pad[3];
    float duration;
    float time;
    char pad2[8];
    Color color;
};
struct Entry {
    unsigned char unk0; unsigned char active : 8; unsigned char unk2, group, unk4, type;
    char pad[2];
    Data data;
};
struct Self {
    Group groups[9];
    char pad[3];
    Entry entries[10];
    gfCameraController* controller;
    unsigned char counts[256];
};
extern "C" void fn_8005DA68(Self*, Data*);
extern "C" void fn_8005DE38(Self*, unsigned char, int);
extern float lbl_805A1918;

extern "C" void fn_8005D7D8(Self* self, float delta) {
    if (!(delta <= lbl_805A1918)) {
        for (int i = 0; i < 10; i++) {
            Entry* entry = &self->entries[i];
            if (entry->active) {
                int keep = 1;
                switch (entry->type) {
                case 0:
                    entry->data.time += delta;
                    if (entry->data.time > entry->data.duration)
                        keep = 0;
                case 1:
                    entry->data.time += delta;
                    if (entry->data.time > entry->data.duration)
                        keep = 0;
                    break;
                case 2:
                    Data* data = &entry->data;
                    if (data->time > data->duration) {
                        if (data->flag)
                            keep = 0;
                        else
                            data->time = data->duration;
                    }
                    fn_8005DA68(self, data);
                    if (!keep) {
                        if (--self->counts[entry->group] == 0) {
                            if (self->controller && entry->group == self->controller->id) {
                                self->controller->slot0(2, data->color);
                            }
                        }
                    }
                    data->time += delta;
                    break;
                }
                if (!keep) {
                    entry->active = 0;
                    fn_8005DE38(self, entry->group, i);
                }
            }
        }
        if (self->controller) {
            unsigned char group = self->controller->id;
            if (self->counts[group]) {
                Group* g = &self->groups[group];
                Color value;
                value.r = 0; value.g = 0; value.b = 0; value.a = 0;
                for (int i = 0; i < g->count; i++) {
                    int index = g->slots[i];
                    if (index >= 0 && self->entries[index].active && self->entries[index].type == 2) {
                        *(unsigned int*)&value = *(unsigned int*)&self->entries[index].data.color;
                    }
                }
                self->controller->slot0(1, value);
            }
        }
    }
}