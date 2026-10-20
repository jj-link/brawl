#pragma force_active on
struct BitStruct {
    int unk0;
    int unk4;
    unsigned int high : 4;
    unsigned int rest : 28;
};

extern "C" void fn_27_390390(BitStruct* p, unsigned int v) {
    p->high = v;
}
