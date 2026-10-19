#pragma force_active on
struct FtPokeObj {
    void* vtable;
    int unk4;
    void* arg;
    int index;
};

extern "C" void fn_116_72AC(FtPokeObj* obj, int kind);
extern "C" unsigned char lbl_116_data_75C8[];

extern "C" FtPokeObj* fn_116_10458(FtPokeObj* obj, void* arg) {
    fn_116_72AC(obj, 0);
    obj->vtable = lbl_116_data_75C8;
    obj->arg = arg;
    obj->index = -1;
    return obj;
}
