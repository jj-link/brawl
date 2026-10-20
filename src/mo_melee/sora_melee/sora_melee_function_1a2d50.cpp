#pragma force_active on
struct Foo {
    unsigned int unk0;
    unsigned int unk4;
    int mFlags;
};

extern "C" int fn_27_1A2D50(Foo* obj) {
    return obj->mFlags >> 30;
}
