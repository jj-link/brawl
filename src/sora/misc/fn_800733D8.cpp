#pragma force_active on

struct In6 { float a, b, c, d, e, f; };
struct Src { float x, y, z; };

extern "C" {
int fn_801C05C0(void*, const In6*);
int fn_801C0234(void*, const Src*);
void* fn_801B77F8();
int fn_801B818C(void*, int, void*);
}

extern "C" void fn_800733D8(unsigned char* self) {
    if (self[0x6EF] != 0) {
        fn_801C05C0(self + 0x728, (const In6*)(self + 0xB6C));
        fn_801C0234(self + 0xA48, (const Src*)(self + 0xB84));
        In6 blk = {0.0f, 1.5f, 0.6f, 0.4f, 0.1f, 1.0f};
        Src b = {200.0f, 0.3f, 1.0f};
        fn_801C05C0(self + 0x8B8, &blk);
        fn_801C0234(self + 0xAD0, &b);
        fn_801B818C(fn_801B77F8(), 1, self + 0x8B8);
        fn_801B818C(fn_801B77F8(), 2, self + 0xAD0);
        if (self[0xB90] & 1) {
            fn_801B818C(fn_801B77F8(), 0, self + 0x728);
        }
        if (self[0xB90] & 2) {
            fn_801B818C(fn_801B77F8(), 0, self + 0xA48);
        }
    }
}
