#pragma force_active on

struct Vec3f {
    float x;
    float y;
    float z;
};

extern "C" {
extern const float lbl_40_rodata_3DC;
void getPos__9grGimmickFv(Vec3f* out, void* self);
void getRot__9grGimmickFv(Vec3f* out, void* self);
}

struct Dest {
    char _pad[0x88];
    Vec3f pos;
    Vec3f rot;
};

extern "C" void fn_40_25D48(void* self) {
    Vec3f pos = {lbl_40_rodata_3DC, lbl_40_rodata_3DC, lbl_40_rodata_3DC};
    Vec3f rot = {lbl_40_rodata_3DC, lbl_40_rodata_3DC, lbl_40_rodata_3DC};
    if (*(void**)((char*)self + 0x150) != 0) {
        Vec3f p;
        Vec3f r;
        getPos__9grGimmickFv(&p, *(void**)((char*)self + 0x150));
        pos = p;
        getRot__9grGimmickFv(&r, *(void**)((char*)self + 0x150));
        rot = r;
    }
    Dest* dest = *(Dest**)((char*)self + 0xD4);
    dest->pos = pos;
    dest = *(Dest**)((char*)self + 0xD4);
    dest->rot = rot;
}
