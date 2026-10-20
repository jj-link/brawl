#pragma force_active on
struct Holder {
    unsigned int pad[2];
    unsigned int hi : 12;
    unsigned int mid : 6;
    unsigned int lo : 14;
};

extern "C" {
void fn_27_296214(Holder *p, unsigned int v) {
    p->mid = v;
}
}
