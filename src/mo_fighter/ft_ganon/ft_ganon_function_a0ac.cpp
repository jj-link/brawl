#pragma force_active on

extern "C" {
extern const char lbl_109_data_5F1C[];
extern const char lbl_109_data_5DA8[];
extern const char lbl_109_data_1A04[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

class Obj {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual unsigned int m6();
};

extern "C" int fn_109_A0AC(void*, void*, void* self) {
    unsigned char buf[40];
    unsigned char* p = buf;
    Obj* obj = reinterpret_cast<Obj*>(self);
    switch (obj->m6()) {
        case 0: p[32] = 0; p[33] = 0; __dynamic_cast(self, 0, lbl_109_data_5F1C, lbl_109_data_1A04, 1); return 1;
        case 1: p[30] = 0; p[31] = 0; __dynamic_cast(self, 0, lbl_109_data_5DA8, lbl_109_data_1A04, 1); return 1;
        case 2: p[28] = 0; p[29] = 0; return 1;
        case 3: p[26] = 0; p[27] = 0; return 1;
        case 4: p[24] = 0; p[25] = 0; return 1;
        case 5: p[22] = 0; p[23] = 0; return 1;
        case 6: p[20] = 0; p[21] = 0; return 1;
        case 7: p[18] = 0; p[19] = 0; return 1;
        case 8: p[16] = 0; p[17] = 0; return 1;
        case 9: p[14] = 0; p[15] = 0; return 1;
        case 10: p[12] = 0; p[13] = 0; return 1;
        case 11: p[10] = 0; p[11] = 0; return 1;
        case 12: p[8] = 0; p[9] = 0; return 1;
        case 13: p[6] = 0; p[7] = 0; return 1;
        case 14: p[4] = 0; p[5] = 0; return 1;
        case 15: p[2] = 0; p[3] = 0; return 1;
        case 16: p[0] = 0; p[1] = 0; return 1;
        default: return 0;
    }
}
