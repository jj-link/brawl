#pragma force_active on
typedef unsigned long long u64;

extern "C" {
extern void* g_ftManager;
int getEntryId__9ftManagerFi(void*, int);
u64 fn_27_10AE98(void*, int, int);
extern float lbl_27_rodata_3930;
}

union Position2 {
    u64 bits;
    struct {
        float x, y;
    } pos;
};

extern "C" void fn_27_239FEC(void*, int slot, float* out) {
    void* manager = g_ftManager;
    Position2 p;
    u64 bits = fn_27_10AE98(
        manager, getEntryId__9ftManagerFi(manager, slot), -1);
    p = *reinterpret_cast<Position2*>(&bits);

    float z = lbl_27_rodata_3930;
    float y = p.pos.y;
    float x = p.pos.x;

    out[0] = x;
    out[1] = y;
    out[2] = z;
}
