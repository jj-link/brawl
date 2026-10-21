#pragma force_active on

extern "C" {
void printf__5MuMsgFUlPCce(void* msg, unsigned long index, const char* fmt, ...);
extern char lbl_10_data_730[];

void fn_10_10384(char* self, unsigned long id)
{
    printf__5MuMsgFUlPCce(*(void**)(self + 0x5C4), id, lbl_10_data_730);
}
}
