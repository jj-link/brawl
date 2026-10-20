#pragma force_active on
extern "C" {
struct ftThing {
    unsigned unk0;
    unsigned unk4;
    unsigned : 18;
    unsigned target : 1;
    unsigned : 13;
};

unsigned fn_27_1CF954(const ftThing* p) {
    return p->target;
}
}
