#pragma force_active on
typedef unsigned long u32;

namespace nw4r {
namespace g3d {
class ScnMdlSimple;
}
}

class MuMsg {
public:
    void attachScnMdlSimple(u32, nw4r::g3d::ScnMdlSimple*, u32, float);
    void setFontColor(u32, unsigned char, unsigned char, unsigned char, unsigned char);
};

struct Model {
    char pad[0x10];
    nw4r::g3d::ScnMdlSimple* mdl;
};

struct Data {
    char pad[0x168];
    Model* a;
    Model* b;
    char pad2[0x1c7c - 0x170];
    MuMsg* msg;
};

struct Object {
    char pad[0x1ac];
    Data* data;
};

struct Ids {
    u32 id[2];
};

extern const Ids lbl_5_rodata_308;
extern const float lbl_5_rodata_310;

extern "C" void fn_6_1ECC(Object*, u32);

extern "C" void fn_5_12E90(Object* self, u32 flags) {
    fn_6_1ECC(self, flags | 4);

    self->data->msg->attachScnMdlSimple(0x11, self->data->a->mdl, 0, lbl_5_rodata_310);
    self->data->msg->setFontColor(0x11, 255, 255, 255, 255);

    self->data->msg->attachScnMdlSimple(0x12, self->data->a->mdl, 1, lbl_5_rodata_310);
    self->data->msg->setFontColor(0x12, 0x45, 0x46, 0x5e, 255);

    self->data->msg->attachScnMdlSimple(0x13, self->data->a->mdl, 2, lbl_5_rodata_310);
    self->data->msg->setFontColor(0x13, 0x45, 0x46, 0x5e, 255);

    Ids ids = lbl_5_rodata_308;
    for (u32 i = 0; i < 2; i++) {
        self->data->msg->attachScnMdlSimple(ids.id[i], self->data->b->mdl, i, lbl_5_rodata_310);
        self->data->msg->setFontColor(ids.id[i], 0, 0, 0, 255);
    }
}
