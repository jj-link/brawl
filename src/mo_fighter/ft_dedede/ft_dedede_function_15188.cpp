#pragma force_active on
struct FtFlags {
    unsigned char pad[0xa4];
    unsigned char a : 1;
    unsigned char b : 1;
};

extern "C" {
bool fn_117_15188(void* self) {
    return ((FtFlags*)self)->b;
}
}
