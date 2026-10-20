#pragma force_active on
struct Fld {
    unsigned int a : 6;
    unsigned int b : 6;
    unsigned int c : 20;
};

extern "C" void fn_27_124DD0(void* p, unsigned int v) {
    Fld* f = (Fld*)((char*)p + 8);
    f->b = v;
}
