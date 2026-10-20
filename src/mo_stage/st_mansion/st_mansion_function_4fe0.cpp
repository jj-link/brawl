#pragma force_active on
struct StageMansion {
    int field0;
    int field4;
    unsigned int a : 4;
    signed int b : 4;
    unsigned int c : 24;
};

extern "C" int fn_47_4FE0(const StageMansion *p) {
    return p->b;
}
