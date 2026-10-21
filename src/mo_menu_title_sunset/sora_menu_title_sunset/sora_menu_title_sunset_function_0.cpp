#pragma force_active on

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void*, const char*, int, int, int, bool);

extern "C" char lbl_25_data_0[];
extern "C" char lbl_25_data_FC[];

struct Task25 {
    char _base[0x3c];
    void* field_3c;
    int field_40;
    int field_44;
    int field_48;
    int field_4c;
    int field_50;
    int field_54;
    int field_58;
    int field_5c;
    int field_60;
    int field_64;
    int field_68;
    int field_6c;
    int field_70;
    int field_74;
    int field_78;
    int field_7c;
    int field_80;
    int field_84;
};

extern "C" void* fn_25_0() {
    Task25* p = (Task25*)__nw__FUlQ25Heaps8HeapType(0x88, 0x2a);
    if (p != 0) {
        __ct__6gfTaskFPCcQ26gfTask8Categoryiib(p, lbl_25_data_0, 8, 0xf, 8, true);
        p->field_3c = lbl_25_data_FC;
        p->field_44 = 0;
        p->field_48 = 0;
        p->field_4c = 0;
        p->field_50 = 0;
        p->field_54 = 0;
        p->field_58 = 0;
        p->field_5c = 0;
        p->field_68 = 0;
        p->field_80 = 0;
    }
    return p;
}
