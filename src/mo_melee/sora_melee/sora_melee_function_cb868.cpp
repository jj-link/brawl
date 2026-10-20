#pragma force_active on
extern "C" {

struct fn_27_Struct {
    int a;
    int b;
    int value : 3;
};

int fn_27_CB868(const fn_27_Struct* p) {
    return p->value;
}

}
