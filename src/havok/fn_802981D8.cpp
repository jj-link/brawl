#pragma force_active on
struct FnObj802981D8 {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
};

extern "C" void* fn_802981D8(FnObj802981D8* obj) {
    return reinterpret_cast<char*>(obj) + (obj->unk8 << 2) + 0x1C;
}
