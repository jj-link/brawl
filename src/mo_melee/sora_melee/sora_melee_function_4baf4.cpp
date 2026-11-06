#pragma force_active on

extern "C" {

void fn_27_3627C(void*, int);
void fn_27_37880(void*, int, float, float);
void fn_27_362E4(void*, int);
void fn_27_36650(void*, int, int);
int fn_27_36028(void*, int, int, void*);
unsigned int fn_27_4AEBC(void*, int, int, int, int, float);
void fn_27_36A8C(void*);
void* fn_27_4FAB4(void*);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);

}

extern void* lbl_27_bss_B8;
extern const float lbl_27_rodata_50C;

class Array {
public:
    virtual void* m0();
    virtual void* at(int);
    virtual void* m2();
    virtual int size();
};

struct Work {
    char pad0[0x28];
    void* unk28;
    Array* entries;
    float f30;
    float f34;
    float f38;
    char pad3c[0x84];
    char obj[0x20];
    unsigned char unkE0;
    char padE1;
    unsigned char unkE2;
};

extern "C" void fn_27_4BAF4(Work* self, float a, float b, float c) {
    void* entry;
    int val;
    unsigned int found;
    int i;
    self->f30 = a;
    found = 0;
    self->f34 = b;
    self->f38 = c;
    fn_27_3627C(&self->obj, 0);
    fn_27_37880(&self->obj, 0, a, lbl_27_rodata_50C);
    fn_27_362E4(&self->obj, 0);
    fn_27_36650(&self->obj, 0, 0);
    int count = self->entries->size();
    for (i = 0; i < count; i++) {
        entry = self->entries->at(i);
        if (*(int*)entry != 0) {
            void* p28 = *(void**)((char*)self->unk28 + 0xD8);
            val = *(int*)((char*)p28 + 4);
            int ret = fn_27_36028(&self->obj, i, 0, p28);
            if (fn_27_4AEBC(entry, val, ret, 0, 0, self->f34) == 1) {
                found = 1;
            }
        }
    }
    if (found == 1) {
        if (lbl_27_bss_B8 == 0) {
            void* p = __nw__FUlQ25Heaps8HeapType(0x1508, 2);
            if (p != 0) {
                p = fn_27_4FAB4(p);
            }
            lbl_27_bss_B8 = p;
        }
        if (!(*(int*)((char*)lbl_27_bss_B8 + 0xB4) & 0x40) || self->unkE0 == 0) {
            fn_27_36A8C(&self->obj);
        }
    }
    self->unkE2 = 1;
}
