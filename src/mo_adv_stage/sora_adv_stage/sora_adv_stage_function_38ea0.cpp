#pragma force_active on
struct Vec2 {
    float x, y;
};

struct Source {
    int value;
    unsigned short a, b, c;
};

struct Entry {
    unsigned char pad[12];
    int value;
    unsigned int a, c;
    unsigned short b, kind;
    Vec2 position;
    unsigned int tail;
};

struct Context {
    unsigned char pad[0xA8];
    Entry* entries;
};

extern "C" void fn_40_38EA0(Context* self, int index, Source* source,
                           unsigned int kind, Vec2 position)
{
    if (source->value > 0) {
        self->entries[index].value = source->value;
        self->entries[index].a = source->a;
        self->entries[index].b = source->b;
        self->entries[index].c = source->c;
        self->entries[index].kind = kind;
        self->entries[index].position = position;
    }
}
