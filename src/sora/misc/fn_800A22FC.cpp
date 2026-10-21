#pragma force_active on
typedef struct Src {
    float x;
    float y;
} Src;

typedef struct Dst {
    char pad[0xB0];
    float x;
    float y;
} Dst;

extern "C" void fn_800A22FC(Dst *a, Src *b) {
    a->x = a->x + b->x;
    a->y = a->y + b->y;
}
