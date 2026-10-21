#pragma force_active on
struct Data {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int flags;
};

extern "C" void fn_27_CE078(Data* data) {
    data->flags &= ~0x80u;
}
