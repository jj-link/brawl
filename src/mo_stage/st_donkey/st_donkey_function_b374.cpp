#pragma force_active on

extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long size, int heap);
void fn_50_1F78(void* self, const char* name);
void __ct__14snd3DGeneratorFv(void* self);
extern char lbl_50_data_2E08[];
extern char lbl_50_data_2BD0[];
}

struct Base {
    char pad[0x3c];
};

struct Sub {
    void* vt;
    void* p4;
    int f8;
};

class Ground : public Base {
public:
#define SLOT(n) virtual void slot##n();
    SLOT(0) SLOT(1) SLOT(2) SLOT(3)
    SLOT(4) SLOT(5) SLOT(6) SLOT(7)
    SLOT(8) SLOT(9) SLOT(10) SLOT(11)
    SLOT(12) SLOT(13) SLOT(14) SLOT(15)
    SLOT(16) SLOT(17) SLOT(18) SLOT(19)
    SLOT(20) SLOT(21) SLOT(22) SLOT(23)
    SLOT(24) SLOT(25) SLOT(26) SLOT(27)
    SLOT(28) SLOT(29) SLOT(30) SLOT(31)
    SLOT(32) SLOT(33) SLOT(34) SLOT(35)
    SLOT(36) SLOT(37) SLOT(38) SLOT(39)
    SLOT(40) SLOT(41)
    virtual void slot42(int);
    SLOT(43) SLOT(44) SLOT(45) SLOT(46)
    SLOT(47) SLOT(48) SLOT(49) SLOT(50)
    SLOT(51) SLOT(52) SLOT(53) SLOT(54)
    SLOT(55) SLOT(56) SLOT(57) SLOT(58)
    SLOT(59) SLOT(60) SLOT(61) SLOT(62)
    SLOT(63) SLOT(64) SLOT(65) SLOT(66)
    SLOT(67) SLOT(68) SLOT(69) SLOT(70)
    SLOT(71) SLOT(72) SLOT(73) SLOT(74)
    SLOT(75) SLOT(76) SLOT(77)
    virtual void slot78(const char*);
#undef SLOT
    char pad40[0xd0 - 0x40];
    Sub sub;
    char padDC[0x164 - 0xdc];
    int f164;
    int f168;
    unsigned char b16c;
    char pad16d[0x170 - 0x16d];
    char gen[0x178 - 0x170];
};

extern "C" Ground* fn_50_B374(int a, const char* b, const char* c) {
    Ground* obj = (Ground*)__nw__FUlQ25Heaps8HeapType(0x178, 0xF);
    if (obj) {
        fn_50_1F78(obj, c);
        *(void**)((char*)obj + 0x3c) = lbl_50_data_2E08;
        obj->f164 = 0;
        obj->f168 = 0;
        obj->b16c = 8;
        Sub* s = &obj->sub;
        if (s) {
            ((unsigned int*)s->p4)[1] |= 1;
        }
        *(void**)((char*)obj + 0x3c) = lbl_50_data_2BD0;
        __ct__14snd3DGeneratorFv(&obj->gen);
    }
    if (obj) {
        obj->slot42(a);
        obj->slot78(b);
    }
    return obj;
}
