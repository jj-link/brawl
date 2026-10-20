#pragma force_active on
extern "C" char lbl_27_data_3EDE8[];

struct Obj {
    void* a;
    void* b;
    unsigned int c;
};

extern "C" {
void fn_27_1A2CEC(Obj* p) {
    char* base = lbl_27_data_3EDE8;
    p->a = base;
    p->b = base + 0x48;
    p->c = p->c & 0x1FFFFFF;
}
}
