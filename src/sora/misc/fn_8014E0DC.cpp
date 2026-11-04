#pragma force_active on
extern "C" int fn_8039A52C();

class NtBuffer {
public:
    virtual void slot0(int, int, int);
};

struct Unk {
    char pad[8];
    NtBuffer* buffer;
};

extern "C" int fn_8014E0DC(Unk* a, int b) {
    int r = 0;
    if ((b <= -16 && b >= -21) || b == -38 || b == -41 || b == -43 || b == -46) {
        int v = fn_8039A52C();
        NtBuffer* o = a->buffer;
        if (o != 0) {
            int av = v;
            if (v < 0) av = -v;
            o->slot0(1, b, av);
        }
    } else if (b == -1 || b == -11 || b == -42) {
        int v = fn_8039A52C();
        NtBuffer* o = a->buffer;
        if (o != 0) {
            int av = v;
            if (v < 0) av = -v;
            o->slot0(3, b, av);
        }
    } else {
        r = 1;
    }
    return r;
}