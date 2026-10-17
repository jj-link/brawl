// fn_101_B07C (.text 0xB07C..0xB148): initializes an embedded effect-support
// block. fn_101_70 at .text 0x800 passes NessEventStorage +0x4853C
// (outer fighter +0x486D0). Calls initializers at block offsets 0, 0x38,
// 0x50, 0x5C, and 0x6C; the +0x5C call receives external lbl_101_data_4.
// The final twelve-word call forwards the accesser, member addresses,
// observer registration, arguments, and literal 10. Returns the block.
typedef unsigned char Byte;
typedef unsigned long Word;

extern "C" {
extern Byte lbl_101_data_4[];
void fn_27_CBEC8(void*, int, int);
void fn_27_1986BC(void*, int, int);
void fn_27_C9FE4(void*, int, int);
void fn_27_D37BC(void*, int, void*, int);
void fn_27_9747C(void*, void*, void*, Word, void*, void*, Word, void*, Word, int, Word, void*);
}

extern "C" void* fn_101_B07C(Byte* effect, void* accesser, Word effectA, Word effectB,
                             Word effectC, Word effectD, void* observers) {
    fn_27_CBEC8(effect, 1, 0);
    fn_27_1986BC(effect + 0x38, 1, 0);
    fn_27_C9FE4(effect + 0x50, 1, 0);
    fn_27_D37BC(effect + 0x5C, 1, lbl_101_data_4, 0);
    fn_27_9747C(effect + 0x6C, accesser, effect, effectA, effect + 0x5C, effect + 0x38,
        effectB, observers, effectC, 10, effectD, effect + 0x50);
    return effect;
}
