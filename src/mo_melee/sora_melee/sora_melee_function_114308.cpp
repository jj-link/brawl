#pragma force_active on
extern "C" {
extern void* getInstance__15gfTaskSchedulerFv();
extern void fn_27_1143B0(char*);
extern unsigned int fn_8004E958(void*);
extern void* g_GameGlobal;
}

struct SchedHeader {
    unsigned int x : 8;
    signed int y : 8;
    unsigned int z : 16;
};

extern "C" void fn_27_114308(char* self, unsigned char arg1) {
    *(unsigned char*)(self + 0x0c) = arg1;
    if (*(unsigned char*)(self + 0x0f) == 3) {
        if (*(unsigned char*)(self + 0x0e) & 1) {
            fn_27_1143B0(self);
            *(unsigned char*)(self + 0x0f) = 3;
        }
    } else {
        void* scheduler = getInstance__15gfTaskSchedulerFv();
        if (scheduler != 0) {
            if (fn_8004E958(g_GameGlobal) == 1) {
                SchedHeader hdr;
                *(int*)&hdr = *(int*)scheduler;
                if (hdr.y <= 1) {
                    fn_27_1143B0(self);
                    return;
                }
            }
            *(unsigned char*)(self + 0x0f) = 5;
        }
    }
}