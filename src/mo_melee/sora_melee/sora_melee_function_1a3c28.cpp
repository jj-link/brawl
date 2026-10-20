#pragma force_active on
struct Obj {
    char* a;
    char* b;
    unsigned int c;
};

extern "C" char lbl_27_data_362B8[];

extern "C" void fn_27_1A3C28(Obj* o) {
    char* p = lbl_27_data_362B8;
    o->a = p;
    o->b = p + 0x48;
    o->c = o->c & 1;
}
