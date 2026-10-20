#pragma force_active on
extern "C" {

struct stSomething {
    unsigned char pad[0x184];
    unsigned char _184;
    unsigned int _188;
    float _18c;
};

void fn_72_F5C(stSomething* a1, unsigned char a, unsigned int b, float c) {
    a1->_184 = a;
    a1->_188 = b;
    a1->_18c = c;
}

}
