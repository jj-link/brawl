#pragma force_active on
typedef unsigned long u32;
typedef unsigned short u16;

u32 SONtoHs(u16);

u32 fn_80388960(void* arg0) {
    u16 s = *(u16*)((char*)arg0 + 4);
    return SONtoHs(s);
}
