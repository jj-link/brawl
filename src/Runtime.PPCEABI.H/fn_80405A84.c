#pragma force_active on
#pragma dollar_identifiers on

extern void fn_8000449C(void* destination, const void* source, unsigned int size);
extern void ICInvalidateRange(const void* buf, unsigned int len);
extern void DCFlushRange(const void* buf, unsigned int len);

extern void PPCHalt(void);
extern unsigned int EndofProgramInstruction$159_80420568[1];

void InitializeProgramEndTrap(void) {
    char* base = (char*)PPCHalt;
    fn_8000449C(base + 4, (const void*)&EndofProgramInstruction$159_80420568[0], 4);
    ICInvalidateRange(base + 4, 4);
    DCFlushRange(base + 4, 4);
}
