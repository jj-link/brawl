#pragma force_active on
struct fn_27_CBFCC_Obj {
    unsigned char pad[8];
    unsigned int mode : 2;
    unsigned int rest : 30;
};

extern "C" {
void fn_27_CBFCC(fn_27_CBFCC_Obj* obj, unsigned int v) {
    obj->mode = v;
}
}
