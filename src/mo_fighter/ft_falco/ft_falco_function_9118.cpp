#pragma force_active on
struct Fn108Obj {
    void* p0;
    int pad4;
    void* p8;
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
};

extern "C" void fn_108_7F30(void* self, int arg);
extern "C" char lbl_108_data_24E4[];

extern "C" void* fn_108_9118(void* self, int a, int b, int c, int d, int e, int f) {
    Fn108Obj* obj = (Fn108Obj*)self;
    fn_108_7F30(self, 0);
    obj->p8 = lbl_108_data_24E4;
    obj->p0 = lbl_108_data_24E4 + 8;
    obj->a = a;
    obj->b = b;
    obj->c = c;
    obj->d = d;
    obj->e = e;
    obj->f = f;
    return self;
}
