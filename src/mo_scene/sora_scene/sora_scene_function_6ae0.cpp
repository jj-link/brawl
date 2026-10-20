#pragma force_active on
typedef unsigned int u32;

struct Inner {
    void* obj;
};

struct Outer {
    char pad[0xc];
    Inner* inner;
};

extern "C" {
void fn_2_85AC(void* obj, u32 a, u32 b);

void fn_1_6AE0(Outer* self, u32 x) {
    fn_2_85AC(self->inner->obj, 1, x);
}
}
