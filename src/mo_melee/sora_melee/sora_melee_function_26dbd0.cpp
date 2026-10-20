#pragma force_active on
extern const float lbl_27_rodata_4388;

struct Vec3 {
    float v[3];

    void set(float x, float y, float z) {
        v[0] = x;
        v[1] = y;
        v[2] = z;
    }
};

struct Node {
    unsigned int unk0;
    unsigned int flags;
    Vec3 pos;
    char padding[0x5c - 0x14];
    float tx;
    char padding2[0xc];
    float ty;
    char padding3[0xc];
    float tz;

    void updatePos() {
        if (flags & 8) {
            pos.set(tx, ty, tz);
        }
    }
};

struct grGimmick {
    char padding[0xd4];
    Node* node;
};

extern "C" void getPos__9grGimmickFv(Vec3* out, grGimmick* self) {
    if (self->node) {
        self->node->updatePos();
        *out = self->node->pos;
        return;
    }

    out->set(lbl_27_rodata_4388, lbl_27_rodata_4388, lbl_27_rodata_4388);
}
