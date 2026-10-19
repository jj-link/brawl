#pragma force_active on
struct FtToonTriple {
    unsigned int a;
    unsigned int b;
    unsigned int c;
};

struct FtToonSelf {
    unsigned int pad;
    FtToonTriple cache;
};

extern "C" FtToonTriple fn_121_B4D0(void* self, void* arg);

extern "C" FtToonTriple* fn_121_B47C(FtToonSelf* self, void* arg) {
    self->cache = fn_121_B4D0(self, arg);
    return &self->cache;
}
