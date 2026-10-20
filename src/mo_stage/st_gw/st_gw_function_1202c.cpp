#pragma force_active on
extern "C" {

void __dl__FPv(void*);
void fn_63_10D0C(void*, int);
extern char lbl_63_data_52D0[];

struct Obj {
    unsigned char _pad1[0x3c];
    void* _field_3c;
    unsigned char _pad2[0x160];
    void* _field_1a0;
};

void* fn_63_1202C(void* a, int b) {
    Obj* p = (Obj*)a;
    if (p) {
        void* sub = p->_field_1a0;
        p->_field_3c = lbl_63_data_52D0;
        if (sub) {
            __dl__FPv(sub);
        }
        p->_field_1a0 = 0;
        fn_63_10D0C(p, 0);
        if (b > 0) {
            __dl__FPv(p);
        }
    }
    return a;
}

}
