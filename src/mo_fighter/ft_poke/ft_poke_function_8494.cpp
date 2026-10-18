#pragma force_active on
struct FtPokeObj {
    void* vt0;
    int pad04;
    void* vt8;
    int w0c;
    int w10;
    int w14;
    int w18;
    int w1c;
    int w20;
};

extern "C" void fn_116_72AC(FtPokeObj* obj, int kind);
extern "C" char lbl_116_data_229C[];

extern "C" FtPokeObj* fn_116_8494(FtPokeObj* obj, int a, int b, int c, int d, int e, int f) {
    fn_116_72AC(obj, 0);
    obj->vt8 = lbl_116_data_229C;
    obj->vt0 = lbl_116_data_229C + 8;
    obj->w0c = a;
    obj->w10 = b;
    obj->w14 = c;
    obj->w18 = d;
    obj->w1c = e;
    obj->w20 = f;
    return obj;
}
