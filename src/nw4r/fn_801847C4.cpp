#include <types.h>
#include <nw4r/math/math_types.h>
#pragma force_active on

struct TexMap {
    u32 w0, w4;
    u16 h8, ha;
    f32 fc, f10;
    u16 h14, h16;
    u32 w18;
};
struct TexCoordGen {
    u8 type, source, matrix, reserved;
    TexCoordGen() {
        reserved = 0;
        type = 1;
        source = 4;
        matrix = 60;
    }
};
struct Material {
    u8 pad[0x38];
    u32 capacity;
    u32 count;
};
struct Obj {
    u8 pad0[0x28];
    Material* material;
    u8 pad2c[0x20];
    nw4r::math::VEC2 size;
    u8 pad54[0x90];
    u8 coords[4];
};
struct TextureSize : nw4r::math::VEC2 {
    TextureSize(const TextureSize& other) {
        x = other.x;
        y = other.y;
    }
};
extern "C" {
void fn_801899A4(Material*, u8);
TexMap* fn_80189904(Material*);
void fn_80189A34(Material*, u32);
TexCoordGen* fn_80189924(Material*);
void fn_8018C27C(void*, u32);
TextureSize fn_8018ACEC(Material*, u32);
}
extern f32 lbl_805A30D8;

inline void SetGen(Material* mat, u8 index, TexCoordGen gen) {
    fn_80189924(mat)[index] = gen;
}
extern "C" void fn_801847C4(Obj* self, const TexMap* map) {
    Material* mat = self->material;
    u32 index = mat->count >> 28;
    if (index >= (mat->capacity >> 28) ||
        index >= ((mat->capacity >> 20) & 15)) {
        return;
    }
    fn_801899A4(mat, (u8)(index + 1));
    fn_80189904(self->material)[index] = *map;
    fn_80189A34(self->material, self->material->count >> 28);
    SetGen(self->material, (u8)index, TexCoordGen());
    fn_8018C27C(self->coords, self->material->count >> 28);
    if (self->size == nw4r::math::VEC2(lbl_805A30D8, lbl_805A30D8)) {
        if ((self->material->count >> 28) == 1) {
            self->size = fn_8018ACEC(self->material, 0);
        }
    }
}
