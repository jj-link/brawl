#pragma force_active on
struct Blk {
    int v[14];
};

extern "C" void fn_80126EA4(char* p) {
    *(Blk*)(p + 0x420) = *(Blk*)(p + 0x370);
}
