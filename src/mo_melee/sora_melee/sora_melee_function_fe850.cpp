#pragma force_active on
extern "C" unsigned int fn_27_FE850(unsigned int* p) {
    struct F {
        unsigned int pad[2];
        unsigned : 6;
        unsigned bit : 1;
    };
    const F* f = (const F*)p;
    return f->bit;
}
