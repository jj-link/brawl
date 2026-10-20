#pragma force_active on
typedef unsigned int u32;

struct Owner;

struct OwnerRef {
    Owner* owner;
};

struct Scene {
    unsigned char padding[0xC];
    OwnerRef* ref;
};

extern "C" u32 fn_2_85AC(Owner* self, u32 index, u32 value);

extern "C" u32 fn_1_6ACC(Scene* self, u32 value) {
    return fn_2_85AC(self->ref->owner, 0, value);
}
