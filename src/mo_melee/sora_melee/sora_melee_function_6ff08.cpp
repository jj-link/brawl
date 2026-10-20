#pragma force_active on
extern void* lbl_27_bss_120[];

extern "C" void* fn_8004570C(void*, unsigned int, unsigned int, unsigned int);

struct Data {
    unsigned int index;
    void* value;
};

extern "C" void fn_27_6FF08(Data* p, unsigned int a, unsigned int b, unsigned int c) {
    p->value = fn_8004570C(lbl_27_bss_120[p->index], a, b, c);
}
