#pragma force_active on
typedef struct S { unsigned char* f0; unsigned char* f4; } S;

extern "C" int fn_27_12100(void* arg0) {
    S* p = *(S**)((char*)arg0 + 0x2C);
    int t;
    if (p != 0) {
        int v;
        unsigned char* r = p->f0;
        unsigned char* q = p->f4;
        v = r[0x57];
        if (q != 0 && r[0x20] == 0 && q[0x20] == 0) {
            if (v == 8) {
                t = 3;
            } else {
                t = 6;
            }
        } else {
            if (v == 0) {
                if (r[0x5C] != 0) t = 4;
                else t = 0;
            } else if (v == 4) {
                if (r[0x5C] != 0) t = 5;
                else t = 1;
            } else if (v == 5) {
                t = 2;
            } else if (v == 6) {
                if (r[0x5C] != 0) t = 5;
                else t = 1;
            } else if (v == 7) {
                t = 6;
            } else if (v == 9) {
                t = 7;
            } else if (v == 0xA) {
                t = 8;
            } else {
                t = 3;
            }
        }
        return (t - 2) == 0;
    }
    return 0;
}
