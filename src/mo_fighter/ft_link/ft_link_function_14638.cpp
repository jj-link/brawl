#pragma force_active on
extern "C" const float lbl_93_rodata_78;

struct LinkFacingPair {
    float padding[2];
    float facing;
    float facing2;
};

extern "C" void fn_93_14638(LinkFacingPair* object) {
    object->facing = object->facing2 = lbl_93_rodata_78;
}
