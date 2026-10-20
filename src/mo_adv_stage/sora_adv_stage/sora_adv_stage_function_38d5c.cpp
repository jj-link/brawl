#pragma force_active on
struct Vec2 {
    float x, y;
};

struct Entry {
    char pad00[0x0C];
    int count;
    int value;
    int state;
    unsigned short timer;
    unsigned short pad1A;
    Vec2 position;
    int pad24;
};

struct Object {
    char pad00[0xA8];
    Entry* entries;
};

extern "C" void fn_40_38D5C(
    Object* self, int index, int count, int value, const Vec2* position)
{
    if (count > 0) {
        float y = position->y;
        float x = position->x;

        self->entries[index].count = count;
        self->entries[index].value = value;
        self->entries[index].timer = 0;
        self->entries[index].state = 0;

        Vec2* dest = &self->entries[index].position;
        dest->x = x;
        dest->y = y;
    }
}
