#pragma force_active on
extern const float lbl_28_rodata_94;

struct Node {
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void setRate(float);
};

struct Inner {
    char pad[8];
    Node* n1;   // 0x08
    Node* n2;   // 0x0C
};

struct Mid {
    char pad[0x14];
    Inner* inner; // 0x14
};

struct SelfObj {
    char pad[0x138];
    Mid* mid;     // 0x138
};

extern "C" int fn_28_1EA4(SelfObj* self) {
    Mid* mid = self->mid;
    mid->inner->n2->setRate(lbl_28_rodata_94);
    mid->inner->n1->setRate(lbl_28_rodata_94);
    return 3;
}
