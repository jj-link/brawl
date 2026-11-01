#pragma force_active on

extern "C" {
extern const float lbl_27_rodata_450;
extern unsigned char lbl_27_data_31B8[];
}

struct Vec2 {
    float x, y;
    Vec2() {}
    Vec2(float a, float b) : x(a), y(b) {}
};

struct Tri {
    unsigned int x, y, z;
    Tri() {}
    Tri(unsigned int v) : x(v), y(v), z(v) {}
};

struct State {
    void* vtable;
    unsigned char flag;
    Tri abc;
    Vec2 first, second;
    unsigned char flag24, flag25;

    void init() {
        flag24 = 0;
        first.x = lbl_27_rodata_450;
        first.y = lbl_27_rodata_450;
        second.x = lbl_27_rodata_450;
        second.y = lbl_27_rodata_450;
        flag = 0;
        abc.x = 0xFFFF;
        vtable = lbl_27_data_31B8;
        abc = Tri(0xFFFF);
        Vec2 v1(lbl_27_rodata_450, lbl_27_rodata_450);
        first = v1;
        Vec2 v2(lbl_27_rodata_450, lbl_27_rodata_450);
        second = v2;
        flag24 = 0;
        flag25 = 0;
    }
};

extern "C" void fn_27_311F8(State* s) {
    s->init();
}
