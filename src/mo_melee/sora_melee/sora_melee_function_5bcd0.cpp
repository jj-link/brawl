#pragma force_active on
extern "C" {
void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void* self, const char* name, int category, int a, int b, bool c);
extern const char lbl_27_data_6300[];
extern const char lbl_27_data_6308[];
extern const float lbl_27_rodata_7C8;

struct fn_27_Obj {
    char pad[0x3C];
    const char* p;
    int i;
    float f;
    unsigned char b;
};

void* fn_27_5BCD0(void* self) {
    fn_27_Obj* o = (fn_27_Obj*)self;
    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(self, lbl_27_data_6300, 0, 0, 13, true);
    o->i = 0;
    o->p = lbl_27_data_6308;
    o->f = lbl_27_rodata_7C8;
    o->b = 0;
    return self;
}
}
