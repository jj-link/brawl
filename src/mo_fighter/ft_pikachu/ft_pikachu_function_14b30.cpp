#pragma force_active on
struct FtFlags {
    unsigned char pad[0xa4];
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char rest : 6;
};

extern "C" int fn_98_14B30(FtFlags* self) {
    return self->b1 != 0;
}
