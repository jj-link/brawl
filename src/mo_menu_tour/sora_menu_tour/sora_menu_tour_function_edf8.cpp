#pragma force_active on
extern "C" void printIndex__5MuMsgFUlUlPv(void*, unsigned long, unsigned long, void*);

extern "C" void fn_3_EDF8(char* self, unsigned long val, int flag) {
    if (flag != 0) {
        printIndex__5MuMsgFUlUlPv(*(void**)(self + 0x48), 0, val, 0);
    }
    *(unsigned long*)(self + 0x40) = val;
}
