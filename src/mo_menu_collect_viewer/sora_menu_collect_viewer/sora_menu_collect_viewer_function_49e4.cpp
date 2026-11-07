#pragma force_active on
struct B { char pad[0x50]; };
struct VObj : B { virtual ~VObj(); };

struct Out {
    int a;
    int b;
    int c;
    VObj* d;
    int e;
};
struct In {
    char pad[0x1ec];
    int a;
    int b;
    int c;
    VObj* d;
    int e;
};

extern "C" void fn_800C2BB4(void*, int);

extern "C" void fn_6_49E4(Out* out, In* in) {
    out->a = 0;
    out->d = 0;
    int t = in->a;
    in->a = 0;
    fn_800C2BB4(out, t);
    out->b = in->b;
    out->c = in->c;
    VObj* n = in->d;
    in->d = 0;
    if (out->d != n) {
        delete out->d;
        out->d = n;
    }
    out->e = in->e;
}