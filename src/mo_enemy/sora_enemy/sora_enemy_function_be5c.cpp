#pragma force_active on
extern "C" void fn_41_BEB0(void*, void*, unsigned int);

typedef unsigned int u32;

struct Vec3u {
    u32 a;
    u32 b;
    u32 c;
};

struct emTestObj {
    u32 unk0;
    Vec3u unk4;
};

extern "C" {
Vec3u* fn_41_BE5C(emTestObj* self, u32 p2) {
    Vec3u tmp;
    fn_41_BEB0(&tmp, self, p2);
    self->unk4 = tmp;
    return &self->unk4;
}
}
