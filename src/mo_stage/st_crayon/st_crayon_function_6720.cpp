#pragma force_active on
struct StCrayonFlagsObj {
    int unk0;
    int unk4;
    unsigned int unk8_hi : 12;
    unsigned int flag : 1;
    unsigned int unk8_lo : 19;
};

extern "C" int fn_56_6720(StCrayonFlagsObj* obj) {
    return obj->flag;
}
