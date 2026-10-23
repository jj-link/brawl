#pragma force_active on

struct Obj {
    int pad[14];
    int field;
};

extern struct Obj* lbl_804F6810[];

void fn_80224CA8(int index, int value) {
    struct Obj* obj = lbl_804F6810[index];
    if (obj->field == 0) {
        obj->field = (value == 0) ? 0 : -3;
    }
}
