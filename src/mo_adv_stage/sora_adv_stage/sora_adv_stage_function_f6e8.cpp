#pragma force_active on

extern "C" {
struct TriggerMng;
extern TriggerMng* g_stTriggerMng;
extern unsigned char lbl_40_data_2070[];
void fn_27_2322E4(TriggerMng*, void*);

void* fn_40_F6E8(void* self, void* item) {
    unsigned int* p = (unsigned int*)self;
    p[0] = 0;
    p[2] = 60;
    p[1] = (unsigned int)lbl_40_data_2070;
    p[3] = 0;
    p[4] = (unsigned int)item;
    unsigned char x = ((unsigned char*)item)[0x14];
    p[5] = (unsigned int)(x != 0);
    fn_27_2322E4(g_stTriggerMng, self);
    return self;
}
}
