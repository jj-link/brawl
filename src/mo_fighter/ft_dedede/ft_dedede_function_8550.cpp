// Initializes the effect-work block at DededeEventStorage +0x44D34
// (outer fighter +0x44EC8), passed by fn_117_70 at .text 0x7F8.
// The five initializers operate at offsets 0, 0x38, 0x50, 0x5C, and 0x6C.
// The final twelve-word call forwards the seven entry arguments, member
// addresses, and literal 10. lbl_117_data_4 remains externally defined.
// Returns the embedded block pointer; original dumps and relocation
// evidence are retained separately from this implementation.

// ABI view of the 0x1A4-byte block initialized by this entry.
struct DededeEffectWork {
    unsigned char calc[0x38];      // +0x00: soArrayVectorCalculator area initialized through fn_27_CBEC8
    unsigned char arrayCalc[0x18]; // +0x38: second calculator area initialized through fn_27_1986BC
    unsigned char shortCalc[0xC];  // +0x50: area initialized through fn_27_C9FE4 and handed to the effect constructor
    unsigned char observers[0x10]; // +0x5C: observer area initialized through fn_27_D37BC
    unsigned char effect[0x138];   // +0x6C: effect object constructed through fn_27_9747C
};

typedef unsigned long Word;

extern "C" {
void fn_27_CBEC8(void* calculator, int kind, int param);
void fn_27_1986BC(void* calculator, int kind, int param);
void fn_27_C9FE4(void* area, int kind, int param);
void fn_27_D37BC(void* observers, int kind, void* param, int flag);
void fn_27_9747C(void* effect, void* accesser, void* owner, Word effectA,
                 void* observers, void* arrayCalc, Word effectB, void* singletons,
                 Word effectC, int index, Word effectD, void* shortCalc);

extern unsigned char lbl_117_data_4[];
}

extern "C" DededeEffectWork* fn_117_8550(DededeEffectWork* work, void* accesser,
                                         Word effectA, Word effectB, Word effectC,
                                         Word effectD, void* singletons) {
    fn_27_CBEC8(work, 1, 0);
    fn_27_1986BC(work->arrayCalc, 1, 0);
    fn_27_C9FE4(work->shortCalc, 1, 0);
    fn_27_D37BC(work->observers, 1, lbl_117_data_4, 0);
    fn_27_9747C(work->effect, accesser, work, effectA, work->observers,
                work->arrayCalc, effectB, singletons, effectC, 0xA, effectD,
                work->shortCalc);
    return work;
}
