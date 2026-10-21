#pragma force_active on

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void __ct__14snd3DGeneratorFv(void*);
extern "C" unsigned char lbl_27_data_57CB0[];
extern "C" unsigned char lbl_27_data_57E00[];
extern "C" const float lbl_27_rodata_4460;

struct Vec3 {
    float x, y, z;

    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}

    Vec3& operator=(const Vec3& other) {
        ((unsigned int*)this)[0] = ((const unsigned int*)&other)[0];
        ((unsigned int*)this)[1] = ((const unsigned int*)&other)[1];
        ((unsigned int*)this)[2] = ((const unsigned int*)&other)[2];
        return *this;
    }
};

struct Input {
    unsigned int word;
    unsigned short half;
};

struct Obj {
    virtual void slot0();
    virtual void slot1();
    virtual void init();

    unsigned int field4;
    float field8;
    unsigned char fieldC, fieldD;
    unsigned short padE;
    int field10;
    Input input;
    Vec3 position;
    float field28;
    unsigned char field2C;
    unsigned char pad2D[3];
    unsigned char generator[8];
    int field38;
};

extern "C" Obj* fn_27_271170(int arg0, const Input* arg1) {
    Obj* obj = (Obj*)__nw__FUlQ25Heaps8HeapType(0x3C, 15);
    if (obj) {
        *(void**)obj = lbl_27_data_57CB0;
        obj->field4 = 0;
        obj->field8 = lbl_27_rodata_4460;
        obj->fieldC = 1;
        obj->fieldD = 0;
        *(void**)obj = lbl_27_data_57E00;
        obj->field10 = arg0;
        obj->input = *arg1;
        obj->position = Vec3(
            lbl_27_rodata_4460,
            lbl_27_rodata_4460,
            lbl_27_rodata_4460
        );
        obj->field28 = lbl_27_rodata_4460;
        obj->field2C = 0;
        __ct__14snd3DGeneratorFv(obj->generator);
        obj->field38 = -1;
        obj->init();
    }
    return obj;
}
