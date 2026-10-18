#pragma force_active on
extern "C" void fn_112_7674(void* obj, unsigned char b);
extern "C" char lbl_112_data_1D28[];

struct FtPitObj {
    void* vtPrimary;   // +0x00 (lbl_112_data_1D28 + 8)
    unsigned int pad04;
    void* vtBase;      // +0x08 (lbl_112_data_1D28)
    int a0C;
    int a10;
    int a14;
    int a18;
    int a1C;
    int a20;
};

extern "C" FtPitObj* fn_112_885C(FtPitObj* obj, int a1, int a2, int a3, int a4, int a5, int a6) {
    fn_112_7674(obj, 0);
    obj->vtBase = lbl_112_data_1D28;
    obj->vtPrimary = lbl_112_data_1D28 + 8;
    obj->a0C = a1;
    obj->a10 = a2;
    obj->a14 = a3;
    obj->a18 = a4;
    obj->a1C = a5;
    obj->a20 = a6;
    return obj;
}
