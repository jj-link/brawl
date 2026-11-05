#pragma force_active on
struct Unk {
    unsigned char padding[0x7D4];
    int field;
};

void fn_803900EC(struct Unk* obj, int val) {
    obj->field = val;
}
