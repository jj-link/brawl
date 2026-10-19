#pragma force_active on
extern "C" char lbl_27_bss_8094[];
extern "C" void fn_27_357B38(void* a, void* b, void* c, void* d);

extern "C" void fn_110_1EF88(void* obj)
{
    char* base = (char*)obj;
    char* p = *(char**)(base + 0xB24C);
    char* q = *(char**)(p + 0x80);
    fn_27_357B38(lbl_27_bss_8094, *(void**)(base + 0x60), base + 0xB250, *(void**)(q + 0x18));
}
