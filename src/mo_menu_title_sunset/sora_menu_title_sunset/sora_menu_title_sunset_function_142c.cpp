#pragma force_active on
struct Params {
    float a;
    float b;
    float c;
    float d;
    char* ptr;
};

extern "C" char lbl_25_data_278[];
extern "C" void fn_25_14C4(void* self);
extern "C" void fn_25_14A0(void* dst, const Params* src);

extern "C" void fn_25_142C(void* self, float a, float b, float c, float d) {
    Params p;
    fn_25_14C4(self);
    p.a = a;
    p.ptr = lbl_25_data_278;
    p.b = b;
    p.c = c;
    p.d = d;
    fn_25_14A0((char*)self + 0x4c, &p);
}
