#pragma force_active on
extern "C" {
extern char lbl_41_data_E4[];
extern char lbl_41_data_132C[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual unsigned int slot6();
};

extern "C" int fn_41_4ABC4(void*, void*, void* self) {
    unsigned char buf[40];
    unsigned char* p = buf;
    Object_vptr_0* obj = reinterpret_cast<Object_vptr_0*>(self);
    switch (obj->slot6()) {
        case 0: p[32] = 0; p[33] = 0; __dynamic_cast(self, 0, lbl_41_data_E4, lbl_41_data_132C, 1); return 1;
        case 1: p[30] = 0; p[31] = 0; return 1;
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
