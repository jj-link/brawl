#pragma force_active on
extern "C" {
extern int lbl_80487A68[];
void fn_8028D8C0(float*, int, int, void*, void*, void*, int, void*);
}
extern "C" void fn_802DC898(void*, int** p, void*, void*, char* base, int i, int j) {
    float v[12] __attribute__((aligned(16)));
    ++*p;
    int k = **p;
    int a = lbl_80487A68[k + 1];
    int b = lbl_80487A68[k + 2];
    char* r6 = base + k * 0x10;
    char* r7 = base + b * 0x10;
    char* r8 = base + a * 0x10;
    v[4] = *(float*)(r8 + 0x50);
    v[5] = *(float*)(r8 + 0x54);
    v[6] = *(float*)(r8 + 0x58);
    v[7] = *(float*)(r8 + 0x5C);
    v[0] = *(float*)(r7 + 0x50);
    v[1] = *(float*)(r7 + 0x54);
    v[2] = *(float*)(r7 + 0x58);
    v[3] = *(float*)(r7 + 0x5C);
    v[8] = *(float*)(r6 + 0x80);
    v[9] = *(float*)(r6 + 0x84);
    v[10] = *(float*)(r6 + 0x88);
    v[11] = *(float*)(r6 + 0x8C);
    fn_8028D8C0(v, i, j, r6, r7, r8, b, &lbl_80487A68);
    float t[4] __attribute__((aligned(16)));
    t[0] = -v[4];
    t[1] = -v[5];
    t[2] = -v[6];
    t[3] = -v[7];
    v[4] = v[0]; v[5] = v[1]; v[6] = v[2]; v[7] = v[3];
    v[0] = t[0]; v[1] = t[1]; v[2] = t[2]; v[3] = t[3];
    ((void (*)(float*, int, int))fn_8028D8C0)(v, i, j);
    *(int*)(base + 0xB8) += 2;
}