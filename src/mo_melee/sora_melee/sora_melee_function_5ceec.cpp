#pragma force_active on
extern "C" float lbl_27_rodata_82C;

struct Vec {
    void* vtable;
    float x;
    float y;
    float z;
    char pad[0x9c - 0x10];
    unsigned char flag;
};

class Sub {
public:
    virtual void v0();
    virtual Vec* v1(int i);
    virtual void v2();
    virtual int v3();
};

struct Self {
    char pad0[0x40];
    Sub* sub;
    char pad1[0x5C];
    int value;
    char pad2[5];
    unsigned char flag;
};

extern "C" void fn_27_5CEEC(Self* self) {
    if (self->flag != 1) {
        int count = self->sub->v3();
        float c = lbl_27_rodata_82C;
        for (int i = 0; i < count; i++) {
            Vec* vec = self->sub->v1(i);
            vec->z = c;
            vec->y = c;
            vec->x = c;
            vec->flag = 0;
        }
    }
    self->value = -1;
}
