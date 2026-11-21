#pragma force_active on

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);

extern "C" unsigned char lbl_27_data_57C38[];
extern "C" unsigned char lbl_27_data_57CB0[];
extern const float lbl_27_rodata_4448;
extern const float lbl_27_rodata_444C;
extern unsigned char lbl_8040ABD8[];

class Object_vptr_0 {
public:
    virtual int slot0(void**);
    virtual void slot1();
    virtual void slot2();
};

struct Obj {
    Object_vptr_0* vptr;
    int unk4;
    float unk8;
    unsigned char unkC;
    unsigned char unkD;
    char pad_e[2];
    Object_vptr_0* unk10;
    float unk14;
    float unk18;
    float unk1C;
    float unk20;
    int unk24;
};

extern "C" Obj* fn_27_2709D8(Object_vptr_0* arg0, int arg1, float farg0) {
    Obj* obj = (Obj*)__nw__FUlQ25Heaps8HeapType(0x28, 0xF);
    if (obj != 0) {
        float fval = (float)(double)farg0;
        float k = lbl_27_rodata_444C;
        obj->vptr = (Object_vptr_0*)lbl_27_data_57CB0;
        obj->unk4 = 0;
        obj->unk8 = lbl_27_rodata_4448;
        obj->unkC = 1;
        int found = 0;
        obj->unkD = 0;
        obj->vptr = (Object_vptr_0*)lbl_27_data_57C38;
        obj->unk14 = farg0;
        obj->unk18 = lbl_27_rodata_4448;
        obj->unk1C = k / fval;
        obj->unk20 = lbl_27_rodata_4448;
        obj->unk24 = arg1;

        if (arg0 != 0) {
            void* key = (void*)lbl_8040ABD8;
            if (arg0->slot0(&key) != 0) {
                found = 1;
            }
        }

        arg0 = (found != 0) ? arg0 : 0;

        obj->unk10 = arg0;
        ((Object_vptr_0*)obj)->slot2();
    }
    return obj;
}
