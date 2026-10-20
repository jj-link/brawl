#pragma force_active on
extern unsigned char lbl_2_rodata_1320[];
extern "C" void printIndex__5MuMsgFUlUlPv(void* msg, unsigned long a, unsigned long b, void* c);

extern "C" void fn_2_3204C(unsigned char* self, int id) {
    unsigned long idx;
    switch (id) {
    case 0x16: idx = 0xb; break;
    case 0x17: idx = 0xc; break;
    case 0x18: idx = 0xd; break;
    case 0x14: idx = 9; break;
    case 0x15: idx = 0xa; break;
    default: {
        unsigned char* p = *(unsigned char**)(self + 0x40);
        unsigned char* q = id + p;
        unsigned char* t = lbl_2_rodata_1320;
        unsigned char b = q[0x19c];
        idx = (t + (b << 1))[1];
        break;
    }
    }
    printIndex__5MuMsgFUlUlPv(*(void**)(*(unsigned char**)(self + 0x40) + 0x164), 1, idx, 0);
}
