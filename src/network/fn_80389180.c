#pragma force_active on
struct UnknownStruct {
    int x0;
    int x4;
    int x8;
    short xC;
};

void fn_80389180(struct UnknownStruct* obj, int a, short int b) {
    obj->x8 = a;
    obj->xC = b;
}
