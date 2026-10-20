#pragma force_active on
struct FnObj40 {
    int unk0;
    int unk4;
    unsigned int flags;
};

extern "C" {
void fn_40_24B84(FnObj40* obj) {
    obj->flags |= 0x02000000;
}
}
