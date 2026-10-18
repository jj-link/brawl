#pragma force_active on
extern char lbl_25_data_278[];

struct FnObj {
    float x;
    float y;
    float z;
    float w;
    char* ptr;
};

extern "C" {
void fn_25_C58(FnObj* o, float a, float b, float c, float d) {
    o->x = a;
    o->ptr = lbl_25_data_278;
    o->y = b;
    o->z = c;
    o->w = d;
}
}
