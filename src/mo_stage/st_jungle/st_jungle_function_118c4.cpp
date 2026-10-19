#pragma force_active on
typedef unsigned char u8;

struct SubState {
    u8 a;
    u8 b;
};

struct Owner {
    char pad[0x194];
    SubState* sub;
};

extern "C" {
void fn_51_118C4(Owner* owner) {
    SubState* s = owner->sub;
    if (s == 0) {
        return;
    }
    if (s->a > 1) {
        s->a = 4;
    }
    s = owner->sub;
    if (s->b > 1) {
        s->b = 4;
    }
}
}
