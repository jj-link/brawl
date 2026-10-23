#pragma force_active on
typedef int s32;

struct Buf {
    s32* buf;
    s32 count;
};

extern "C" void fn_802AA324(Buf* f, s32* v) {
    f->buf[f->count++] = *v;
}
