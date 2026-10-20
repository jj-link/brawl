#pragma force_active on
extern "C" {

struct CrayonBits {
    char pad[8];
    unsigned rest : 6;
    unsigned flag : 1;
    unsigned flags : 25;
};

void fn_56_6388(CrayonBits* s) {
    s->flag = 0;
}

}
