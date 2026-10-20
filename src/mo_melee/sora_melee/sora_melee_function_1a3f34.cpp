#pragma force_active on
extern "C" {
struct Obj {
    unsigned int *begin;
    unsigned int *end;
    unsigned int flag;
};

extern unsigned char lbl_27_data_35FD0[];

void fn_27_1A3F34(Obj *obj) {
    unsigned int flag = obj->flag;
    unsigned int *base = (unsigned int *)lbl_27_data_35FD0;
    unsigned int *limit = (unsigned int *)((char *)base + 0x48);
    obj->begin = base;
    obj->end = limit;
    obj->flag = flag & 1;
}
}
