#pragma force_active on
extern "C" char lbl_25_data_278[];

struct Params {
    float a, b, c, d;
    char* ptr;

    Params(const Params& other) {
        ptr = lbl_25_data_278;
        a = other.a;
        b = other.b;
        c = other.c;
        d = other.d;
    }
};

extern "C" void fn_25_DC0(void*, const Params*, const Params*, float);

extern "C" void fn_25_13A8(void* self, const Params* first,
                           const Params* second, float t) {
    Params p(*first);
    Params q(*second);
    fn_25_DC0((char*)self + 0x4c, &p, &q, t);
}
