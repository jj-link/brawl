#pragma force_active on

typedef unsigned int u32;
typedef unsigned char u8;

extern "C" u32 fn_80111CB0(void*, void*);
extern "C" void fn_80111E84(void*, void*, void*, void*);
extern float lbl_805A2918;

struct QBits {
    u8 hi : 1;
    u8 rest : 7;
};

struct ID {
    u32 value;
};

struct Line {
    u32 a, b, c;
    u8 d;
    QBits q;

    Line() {
        a = 0;
        b = 0;
        c = 0;
        d = 0;
        q.hi = 0;
    }
};

extern "C" void fn_80111DE4(ID arg0, void* arg1, float* arg2) {
    float temp[2];
    Line l;
    ID id = arg0;

    if (fn_80111CB0(&id, &l) != 0) {
        fn_80111E84(&l, arg1, temp, arg2);
    } else {
        float f = lbl_805A2918;
        arg2[0] = f;
        arg2[1] = f;
    }
}
