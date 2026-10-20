#pragma force_active on
extern "C" {
void fn_27_1D49FC(void*);
void fn_27_1D6078(void*);
void fn_27_1D60BC(void*);
void fn_27_1D6144(void*);
void fn_27_1D6100(void*);
void fn_27_1D6188(void*);
void fn_27_1D71A4(void*);
void fn_27_1D548C(void*);
void fn_27_1D4B80(void*, void*);
void fn_27_1D512C(void*);

void* fn_27_1D48C0(void* p) {
    struct Obj {
        char before[0x1B0];
        char member[1];
    } *obj = (Obj*)p;

    fn_27_1D49FC(obj->member);
    fn_27_1D6078((char*)obj + 0x3FC);
    fn_27_1D60BC((char*)obj + 0x3FD);
    fn_27_1D6144((char*)obj + 0x3FE);
    fn_27_1D6100((char*)obj + 0x3FF);
    fn_27_1D6188((char*)obj + 0x400);
    *(int*)((char*)obj + 0x404) = 0;
    *(int*)((char*)obj + 0x408) = 0;
    fn_27_1D71A4((char*)obj + 0x40C);
    fn_27_1D548C((char*)obj + 0x490);
    fn_27_1D4B80(obj->member, obj);
    fn_27_1D512C(obj->member);
    return obj;
}
}
