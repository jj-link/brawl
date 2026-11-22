#pragma force_active on
struct Elem {
    unsigned char pad0[0x10];
    float f10;
    unsigned char pad_a[4];
    unsigned char b18;
    unsigned char pad1[3];
    float f1c;
};

extern "C" const float lbl_68_rodata_20[];
#define rd lbl_68_rodata_20

extern "C" void fn_68_380C(void* obj, float farg0) {
    Elem* p = (Elem*)((char*)obj + 0x1f8);
    int n = *((unsigned char*)p + 0x7c6) + 1;

    for (int i = 0; i != n; i++) {
        float t = p->f1c - farg0;
        p->f1c = t;

        if (t < rd[3]) {
            p->f1c = rd[3];
        }

        switch (p->b18) {
        case 0:
            break;
        case 1: {
            float v = rd[20] - p->f1c / rd[21];

            if (v < rd[3]) {
                v = rd[3];
            }
            if (v > rd[20]) {
                v = rd[20];
            }

            float w = rd[22] - rd[22] * v;
            p->f10 = w;

            if (w < rd[3]) {
                p->f10 = rd[3];
            }
            if (rd[3] == p->f1c) {
                p->f10 = rd[3];
                p->b18 = 0;
            }
            break;
        }
        }

        p++;
    }
}
