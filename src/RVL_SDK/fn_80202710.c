#pragma force_active on
extern int lbl_8047B140[];
extern char lbl_8047B200[];
extern float lbl_805A3918;

int fn_80202710(void *arg0) {
    float f = lbl_805A3918 * *(float*)((char*)arg0 + 0x114);
    int r = lbl_8047B140[23] + (int)f;
    r += *(int*)(lbl_8047B200 + 0xC0);
    r += *(int*)(lbl_8047B200 + 0xC4);
    r += *(int*)(lbl_8047B200 + 0xC8);
    r += *(int*)(lbl_8047B200 + 0xCC);
    r += *(int*)(lbl_8047B200 + 0xD0);
    r *= 3;
    r += *(int*)(lbl_8047B200 + 0xD4);
    r += *(int*)(lbl_8047B200 + 0xD8);
    r += *(int*)(lbl_8047B200 + 0xDC);
    return r * 4;
}
