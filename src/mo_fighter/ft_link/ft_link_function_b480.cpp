#pragma force_active on
typedef unsigned int u32;

struct FtLinkTriple {
    u32 a;
    u32 b;
    u32 c;
};

struct FtLinkObj {
    u32 pad;
    FtLinkTriple t;
};

extern "C" {
void fn_93_B4D4(FtLinkTriple* out, void* self, void* b);

FtLinkTriple* fn_93_B480(FtLinkObj* self, void* b) {
    FtLinkTriple local;
    fn_93_B4D4(&local, self, b);
    self->t = local;
    return &self->t;
}
}
