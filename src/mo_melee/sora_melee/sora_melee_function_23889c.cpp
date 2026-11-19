#pragma force_active on

struct Vec2 {
    float x;
    float y;
};

struct Rect {
    Vec2 min;
    Vec2 max;
};

inline bool operator!=(const Rect& lhs, Rect rhs) {
    return (lhs.min.x != rhs.min.x) | (lhs.min.y != rhs.min.y) | (lhs.max.x != rhs.max.x) | (lhs.max.y != rhs.max.y);
}

struct Entry {
    int flags;
    int id;
    int value;
    float dx;
    float dy;
    char pad[8];
    Rect color;
};

struct Interface {
    void* vtable;
    unsigned int count1;
    unsigned int count2;
    unsigned int count3;
    unsigned int count4;
    void* p1;
    void* p2;
    void* p3;
    Entry* entries;
};

extern "C" void fn_27_23889C(Interface* self, unsigned int index, Rect* color) {
    if (self->entries[index].color != *color) {
        self->entries[index].flags |= 8;
        self->entries[index].color = *color;
    }
}