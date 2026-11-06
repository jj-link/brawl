#pragma force_active on

struct SunsetTitleState {
    float v[4];
    char* ptr;
};

struct Entry {
    unsigned char flag;
    unsigned char pad1[3];
    float t;
    unsigned char c1[4];
    unsigned char c2[4];
};

struct Owner {
    unsigned char pad0[0x40];
    void* unk40;
    unsigned char pad44[0x184 - 0x44];
    Entry* unk184;
};

extern "C" void fn_25_C30(SunsetTitleState* dst);
extern "C" void fn_25_13A8(void* self, const SunsetTitleState* first, const SunsetTitleState* second, float t);
extern "C" void* fn_25_C78(void* p, int n);
extern "C" char lbl_25_data_278[];
extern "C" const float lbl_25_rodata_68;

extern "C" void fn_25_35AC(Owner* self, int index) {
    if (self->unk40 != 0 && self->unk184[index].flag != 0) {
        float t = self->unk184[index].t;
        SunsetTitleState a;
        fn_25_C30(&a);
        a.v[0] = self->unk184[index].c1[0] / lbl_25_rodata_68;
        a.v[1] = self->unk184[index].c1[1] / lbl_25_rodata_68;
        a.v[2] = self->unk184[index].c1[2] / lbl_25_rodata_68;
        a.v[3] = self->unk184[index].c1[3] / lbl_25_rodata_68;

        SunsetTitleState b;
        fn_25_C30(&b);
        b.v[0] = self->unk184[index].c2[0] / lbl_25_rodata_68;
        b.v[1] = self->unk184[index].c2[1] / lbl_25_rodata_68;
        b.v[2] = self->unk184[index].c2[2] / lbl_25_rodata_68;
        b.v[3] = self->unk184[index].c2[3] / lbl_25_rodata_68;

        SunsetTitleState p1;
        p1.ptr = lbl_25_data_278;
        p1.v[0] = a.v[0];
        p1.v[1] = a.v[1];
        p1.v[2] = a.v[2];
        p1.v[3] = a.v[3];

        SunsetTitleState p2;
        p2.ptr = lbl_25_data_278;
        p2.v[0] = b.v[0];
        p2.v[1] = b.v[1];
        p2.v[2] = b.v[2];
        p2.v[3] = b.v[3];

        fn_25_13A8(self->unk40, &p1, &p2, t);
        fn_25_C78(&p2, -1);
        fn_25_C78(&p1, -1);
        fn_25_C78(&b, -1);
        fn_25_C78(&a, -1);
    }
}
