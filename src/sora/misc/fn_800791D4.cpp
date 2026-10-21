#pragma force_active on
extern "C" {
extern void* g_sndSystem;
void fn_800741EC(void*, int, int);

void fn_800791D4(char* arg0, int arg1) {
    *(int*)(arg0 + 0x17C) = arg1;
    *(int*)(arg0 + 0x180) = 0;
    fn_800741EC(g_sndSystem, *(int*)(arg0 + 0x178), arg1);
}
}
