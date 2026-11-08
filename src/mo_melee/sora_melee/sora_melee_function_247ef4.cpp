#pragma force_active on
typedef unsigned char u8;

extern "C" void fn_800E3388(void*, int);
extern "C" u8* g_IfMngr;

extern "C" void fn_27_247EF4(u8* self, int arg1, int arg2) {
    u8* p = *(u8**)(self + 0x44);
    if ((p[0xb] >> 2) & 1) {
        u8* mgr = g_IfMngr;
        if (mgr != 0) {
            if (p[0x13] == 1) {
                int off2 = arg2 * 0x5C;
                int off1 = arg1 * 0x5C;
                u8* base = p + 0xa3;
                if (base[off1] == base[off2]) {
                    u8* q1 = p + off1;
                    fn_800E3388(*(void**)(mgr + q1[0x9a] * 4 + 0x4c), -1);
                    u8* q2 = *(u8**)(self + 0x44) + off2;
                    fn_800E3388(*(void**)(g_IfMngr + q2[0x9a] * 4 + 0x4c), -1);
                    return;
                }
            }
            u8* q3 = p + arg1 * 0x5C;
            fn_800E3388(*(void**)(mgr + q3[0x9a] * 4 + 0x4c), 1);
            u8* q4 = *(u8**)(self + 0x44) + arg2 * 0x5C;
            fn_800E3388(*(void**)(g_IfMngr + q4[0x9a] * 4 + 0x4c), -1);
        }
    }
}
