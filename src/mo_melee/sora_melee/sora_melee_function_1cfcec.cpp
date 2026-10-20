#pragma force_active on
extern "C" {

struct _1CFCEC_struct {
    int m_0;
    int m_4;
    unsigned low : 15;
    unsigned value : 1;
    unsigned high : 16;
};

int fn_27_1CFCEC(_1CFCEC_struct* p) {
    return p->value;
}

}
