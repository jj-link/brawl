#pragma force_active on
struct Header {
    int unk0;
    int unk4;
    int flags;
};

extern "C" int fn_27_3902CC(const Header* h) {
    return h->flags >> 29;
}
