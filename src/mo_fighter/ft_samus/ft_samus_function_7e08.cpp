#pragma force_active on
extern "C" void fn_94_6C20(void* obj, unsigned char val);
extern "C" char lbl_94_data_45AC[];

struct Samus94Work {
    void* vtA;
    int w04;
    void* vtB;
    int w0c;
    int w10;
    int w14;
    int w18;
    int w1c;
    int w20;
};

extern "C" void* fn_94_7E08(void* self, int a1, int a2, int a3, int a4, int a5, int a6) {
    Samus94Work* obj = (Samus94Work*)self;
    fn_94_6C20(self, 0);
    obj->vtB = lbl_94_data_45AC;
    obj->vtA = lbl_94_data_45AC + 8;
    obj->w0c = a1;
    obj->w10 = a2;
    obj->w14 = a3;
    obj->w18 = a4;
    obj->w1c = a5;
    obj->w20 = a6;
    return self;
}
