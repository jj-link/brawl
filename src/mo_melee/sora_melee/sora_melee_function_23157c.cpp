#pragma force_active on

class Type1Base {
public:
    int m_data;
};

class Type1Obj : public Type1Base {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(int);
};

struct Type3Data {
    int d[15];
};

class Type3Obj : public Type3Data {
public:
    virtual void h0();
    virtual void h1();
    virtual void h2();
    virtual void h3();
    virtual void h4();
    virtual void h5();
    virtual void h6();
    virtual void h7();
    virtual void h8();
    virtual void h9();
    virtual void h10();
    virtual void h11();
    virtual void h12();
    virtual void h13();
    virtual void h14();
    virtual void h15();
    virtual void h16();
    virtual void h17();
    virtual void h18();
    virtual void h19();
    virtual void h20();
    virtual void h21();
    virtual void h22();
    virtual void h23();
    virtual void h24();
    virtual void h25();
    virtual void h26();
    virtual void h27();
    virtual void h28();
    virtual void h29();
    virtual void h30();
    virtual void h31();
    virtual void h32();
    virtual void h33();
    virtual void h34();
    virtual void h35();
    virtual void h36();
    virtual void h37();
    virtual void h38();
    virtual void h39();
    virtual void h40();
    virtual void h41();
    virtual void h42();
    virtual void h43();
    virtual void h44();
    virtual void h45();
    virtual void h46();
    virtual void h47();
    virtual void h48();
    virtual void h49();
    virtual void h50();
    virtual void h51();
    virtual void h52();
    virtual void h53();
    virtual void h54();
    virtual void h55();
    virtual void h56();
    virtual void h57();
    virtual void h58();
    virtual void h59();
    virtual void h60();
    virtual void h61();
    virtual void h62();
    virtual void h63();
    virtual void h64();
    virtual void h65();
    virtual void h66();
    virtual void h67();
    virtual void h68();
    virtual void h69();
    virtual void h70();
    virtual void h71();
    virtual void h72();
    virtual void h73();
    virtual void h74();
    virtual void h75();
    virtual void h76();
    virtual void h77();
    virtual void h78();
    virtual void h79();
    virtual void h80();
    virtual void h81();
    virtual void h82();
    virtual void h83();
    virtual void h84();
    virtual void h85();
    virtual void h86();
    virtual void h87();
    virtual void h88();
    virtual void h89();
    virtual void h90();
    virtual void h91();
    virtual void h92();
    virtual void h93();
    virtual void h94();
    virtual void h95();
    virtual void h96();
    virtual void h97();
    virtual void h98();
    virtual void h99();
};

struct Entry {
    int _00;
    int _04;
    Type3Obj* _08;
    int _0c;
    Type1Obj* _10;
    int _14;
};

struct MainObj {
    char _00[0x1e7];
    unsigned char _1e7;
    char _1e8[0xD8];
    int _2c0;
    char _2c4[0x230];
    Entry _4f4[1];
};

extern "C" void fn_27_23157C(MainObj* self) {
    if (!(self->_1e7 & 4)) {
        int n = self->_2c0;
        Entry* p = self->_4f4;
        int i = 0;
        while (i < n) {
            unsigned t = p->_04 & 0xF;
            if (t == 1) {
                Type1Obj* obj = p->_10;
                if (obj != 0) {
                    obj->f4(0);
                }
            } else if (t == 3) {
                Type3Obj* obj = p->_08;
                if (obj != 0) {
                    obj->h99();
                }
            }
            i++;
            p++;
        }
        self->_1e7 |= 4;
    }
}
