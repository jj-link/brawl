#pragma force_active on
extern unsigned char lbl_41_rodata_C90[];

struct Data {
    int field00;
    float field04;
    float field08;
    float field0C;
    unsigned char pad10[12];
    float field1C;
    float field20;
    float field24;
    float field28;
    bool field2C;
    int field30;
    int field34;
    float field38;
    float field3C;
};

extern "C" void fn_41_1CBCC(Data* p) {
    float* data = (float*)lbl_41_rodata_C90;
    p->field00 = -1;
    float a = data[3];
    p->field04 = a;
    p->field0C = a;
    float b = data[7];
    p->field1C = b;
    p->field24 = b;
    p->field28 = b;
    p->field2C = false;
    p->field30 = 0;
    p->field34 = -1;
    p->field38 = b;
    p->field3C = data[0];
}
