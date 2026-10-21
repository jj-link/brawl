#pragma force_active on
int fn_803C75A0(void* p, int v);

int fn_803CA8A4(void* p) {
    return -0x15 & ~-((fn_803C75A0(p, 0x200) == 0) & 1);
}
