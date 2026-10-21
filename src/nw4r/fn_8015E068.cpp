#pragma force_active on
extern "C" {
int fn_8015E068(void* arg0) {
    unsigned char* p = *(unsigned char**)((char*)arg0 + 0x14);
    return p[0x14] - p[0x16];
}
}
