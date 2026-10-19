#pragma force_active on
extern "C" {
extern char* g_GameGlobal;
char* fn_8004E6A0(char* g);
int fn_8004F258(unsigned int* out, unsigned int b, int c);
}

extern "C" unsigned int fn_2_1EB24() {
    unsigned int local = *(unsigned int*)fn_8004E6A0(g_GameGlobal);
    unsigned int v = *(unsigned int*)(*(char**)((char*)g_GameGlobal + 0x24) + 0x7f4);
    fn_8004F258(&local, v / 60, -1);
    return local;
}
