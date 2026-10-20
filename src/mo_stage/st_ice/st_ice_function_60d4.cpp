#pragma force_active on
extern "C" {

struct Target {
    int a;
    int b;
    unsigned c : 4;
    unsigned d : 2;
    unsigned e : 26;
};

void fn_62_60D4(Target* self, unsigned int param) {
    self->d = param & 3;
}

}
