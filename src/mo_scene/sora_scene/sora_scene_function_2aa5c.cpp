#pragma force_active on

extern "C" int randi__Fl(long);

struct Obj {
    char _00[0x12];
    unsigned char m_12[9];
    char _1b[0x1b - 0x12 - 9];
    unsigned char m_1b;
};

extern "C" void fn_1_2AA5C(Obj* self) {
    unsigned char buf[9];
    unsigned char* p;
    int k;
    int found;
    int j;
    int i;
    int n;
    int m;

    for (i = 0; i < 9; i++) {
        p = buf;
        n = 0;
        for (k = 0; k < 9; k++) {
            found = 0;
            for (j = 0; j < i; j++) {
                if (k == self->m_12[j]) {
                    found = 1;
                    break;
                }
            }
            if (found == 0) {
                *p = k;
                p++;
                n++;
            }
        }
        self->m_12[i] = buf[randi__Fl(n * 1000) % n];
    }

    for (m = 0; m < 9; m++) {
        if (self->m_12[m] > 3U) {
            self->m_12[m]++;
        }
        if (self->m_12[m] == 3) {
            if (randi__Fl(99) % 2 != 0) {
                self->m_12[m]++;
            }
        }
    }
    self->m_1b = 10;
}
