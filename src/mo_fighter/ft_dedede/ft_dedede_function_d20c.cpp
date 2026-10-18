#pragma force_active on
struct F2Word {
    int a;
    int b;
};

struct PairHolder {
    void* vtable;
    void* unk4;
    F2Word pair;
};

extern "C" F2Word fn_117_D20C(PairHolder* arg)
{
    return arg->pair;
}
