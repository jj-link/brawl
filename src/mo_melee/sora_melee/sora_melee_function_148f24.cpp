#pragma force_active on
struct Entry;
extern Entry lbl_27_bss_3210[];

extern "C" {
void* fn_27_148F24()
{
    char* base = (char*)lbl_27_bss_3210;
    char* p = *(char**)(base + 0x138);
    return *(void**)(p + 0xA8);
}
}
