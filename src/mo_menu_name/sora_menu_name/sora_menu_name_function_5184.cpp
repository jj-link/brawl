#pragma force_active on
extern "C" void printIndex__5MuMsgFUlUlPv(void*, unsigned long, unsigned long, void*);
extern "C" void fn_16_6DB0(void*);

extern "C" void fn_16_5184(char* self) {
    printIndex__5MuMsgFUlUlPv(
        *(void**)(self + 0x154), 6, 8, *(void**)(self + 0x458));
    self[0x474] = 0;
    fn_16_6DB0(*(void**)(self + 0x408));
}
