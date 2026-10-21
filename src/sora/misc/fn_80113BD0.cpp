#pragma force_active on

extern "C" {

void fn_80113BD0(void* arg0, float* dst) {
    void* p1 = *(void**)arg0;
    void* p2 = *(void**)((char*)arg0 + 8);
    unsigned short idx = *(unsigned short*)p1;
    float* base = *(float**)((char*)p2 + 0x10);
    float* src = base + idx * 4;
    dst[0] = src[0];
    dst[1] = src[1];
}

}
