#pragma force_active on
typedef unsigned short u16;

extern u16 SONtoHs(u16);

void fn_803889B0(void* arg0) {
    SONtoHs(*(u16*)((char*)arg0 + 0xC));
}
