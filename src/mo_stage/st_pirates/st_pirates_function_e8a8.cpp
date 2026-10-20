#pragma force_active on
extern "C" {
    void* fn_52_35D0(void* self, const char* name);
    void __ct__14snd3DGeneratorFv(void*);
    extern unsigned int lbl_52_data_300C[];
    extern const float lbl_52_rodata_280;
}

struct Gen { int a; int b; };

struct Pir {
    char pad_00[0x3c];
    void* vtable2;
    char pad_40[0x160 - 0x40];
    int f160;
    char b164;
    char b165;
    char pad166[2];
    int f168;
    char b16c;
    char pad16d[3];
    int f170;
    char b174;
    char pad175[3];
    float f178;
    int f17c;
    int f180;
    int f184;
    Gen gen;
    char b190;
};

extern "C" void* fn_52_E8A8(void* self, const char* name) {
    Pir* p = (Pir*)self;
    fn_52_35D0(self, name);
    p->vtable2 = (void*)&lbl_52_data_300C;
    __ct__14snd3DGeneratorFv(&p->gen);
    p->f160 = 0;
    p->b164 = 0;
    p->b165 = 0;
    p->f168 = 0;
    p->b16c = 0;
    p->f170 = 0;
    p->b174 = 3;
    p->f178 = lbl_52_rodata_280;
    p->f17c = 0;
    p->f180 = 0;
    p->f184 = 0;
    p->b190 = 0;
    return self;
}
