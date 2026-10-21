#pragma force_active on
typedef unsigned long Word;

struct DededeEffectWork {
    unsigned char calc[0x38];      // +0x00
    unsigned char arrayCalc[0x18]; // +0x38
    unsigned char shortCalc[0xC];  // +0x50
    unsigned char observers[0x10]; // +0x5C
    unsigned char effect[0x138];   // +0x6C
};

extern "C" {
void fn_27_CBEC8(void* calculator, int kind, int param);
void fn_27_1986BC(void* calculator, int kind, int param);
void fn_27_C9FE4(void* area, int kind, int param);
void fn_27_D37BC(void* observers, int kind, void* param, int flag);
void fn_27_9747C(void* effect, void* accesser, void* owner, Word effectA,
                 void* observers, void* arrayCalc, Word effectB, void* singletons,
                 Word effectC, int index, Word effectD, void* shortCalc);

extern unsigned char lbl_108_data_4[];
}

extern "C" DededeEffectWork* fn_108_9A0C(DededeEffectWork* work, void* accesser,
                                         Word effectA, Word effectB, Word effectC,
                                         Word effectD, void* singletons) {
    fn_27_CBEC8(work, 1, 0);
    fn_27_1986BC(work->arrayCalc, 1, 0);
    fn_27_C9FE4(work->shortCalc, 1, 0);
    fn_27_D37BC(work->observers, 1, lbl_108_data_4, 0);
    fn_27_9747C(work->effect, accesser, work, effectA, work->observers,
                work->arrayCalc, effectB, singletons, effectC, 0xA, effectD,
                work->shortCalc);
    return work;
}
