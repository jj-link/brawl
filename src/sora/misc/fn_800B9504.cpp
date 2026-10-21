#pragma force_active on
struct MuMsgEntry {
    char pad[0x38];
    float a;
    float b;
    float c;
    float d;
};

struct MuMsg {
    char pad0[0xC];
    MuMsgEntry *entries;

    void setDelayPrint(unsigned long idx, float f1, float f2, float f3, float f4);
};

void MuMsg::setDelayPrint(unsigned long idx, float f1, float f2, float f3, float f4) {
    MuMsgEntry *e = entries + idx;
    e->a = f1;
    e->b = f2;
    e->c = f3;
    e->d = f4;
}
