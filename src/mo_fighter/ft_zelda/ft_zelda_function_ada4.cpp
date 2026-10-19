#pragma force_active on
struct ZeldaArrayTriple {
    unsigned int c;
    unsigned int a;
    unsigned int b;
};

struct ZeldaArrayAggregate;

extern "C" ZeldaArrayTriple fn_104_AC78(ZeldaArrayAggregate* arrays, int index);

extern "C" const ZeldaArrayTriple& fn_104_ADA4(ZeldaArrayAggregate* arrays, int index) {
    return fn_104_AC78(arrays, index);
}
