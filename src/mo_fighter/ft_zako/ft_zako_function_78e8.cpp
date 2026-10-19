#pragma force_active on
struct ZakoArrayTriple {
    unsigned int c;
    unsigned int a;
    unsigned int b;
};

struct ZakoArrayAggregate;

extern "C" ZakoArrayTriple fn_126_77BC(ZakoArrayAggregate* arrays, int index);

extern "C" const ZakoArrayTriple& fn_126_78E8(ZakoArrayAggregate* arrays, int index) {
    return fn_126_77BC(arrays, index);
}
