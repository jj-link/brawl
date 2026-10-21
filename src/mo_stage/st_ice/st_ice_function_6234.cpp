#pragma force_active on
extern "C" {

struct Obj {
    int pad[2];
    unsigned int a : 8;
    unsigned int b : 4;
    unsigned int c : 16;
};

void fn_62_6234(Obj *self, unsigned int val) {
    self->b = val;
}

}
