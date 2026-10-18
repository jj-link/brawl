#pragma force_active on
struct FnStruct81 {
    int unk0;
    int unk4;
};

extern "C" int fn_81_3F00(void* unused, FnStruct81* p) {
    return p->unk4;
}
