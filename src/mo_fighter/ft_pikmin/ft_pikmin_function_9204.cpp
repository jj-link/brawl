#pragma force_active on
struct Fn113Obj {
    void* vtA;      // +0x00
    int unk04;      // +0x04
    void* vtB;      // +0x08
    int f0c;        // +0x0C
    int f10;        // +0x10
    int f14;        // +0x14
    int f18;        // +0x18
    int f1c;        // +0x1C
    int f20;        // +0x20
};

extern "C" void fn_113_7F94(Fn113Obj* obj, int value);
extern "C" char lbl_113_data_1EEC[];

extern "C" Fn113Obj* fn_113_9204(Fn113Obj* obj, int a, int b, int c, int d, int e, int f) {
    fn_113_7F94(obj, 0);
    obj->vtB = (void*)lbl_113_data_1EEC;
    obj->vtA = (void*)(lbl_113_data_1EEC + 8);
    obj->f0c = a;
    obj->f10 = b;
    obj->f14 = c;
    obj->f18 = d;
    obj->f1c = e;
    obj->f20 = f;
    return obj;
}
