#pragma force_active on
extern "C" unsigned int fn_27_2EFA0(char* obj, float* out) {
    char* inner = *(char**)(obj + 4);
    out[0] = *(float*)(inner + 0x84);
    out[1] = *(float*)(inner + 0x88);
    return ((unsigned char)inner[0x73] >> 7) & 1;
}
