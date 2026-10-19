#pragma force_active on
struct snd3DGenerator { char _pad[8]; };

extern "C" {
float randf__Fv();
void playSE__14snd3DGeneratorF5SndIDiii(snd3DGenerator*, int, int, int, int);
}

extern const float lbl_46_rodata_F8[];

struct _ft {
    char _pad[0x168];
    snd3DGenerator _se;   /* 0x168 */
    float _val;          /* 0x170 */
};

extern "C" void fn_46_5510(void* a, float b) {
    const float* p = lbl_46_rodata_F8;
    _ft* s = (_ft*)a;
    s->_val -= b;
    if (s->_val < p[2])
        s->_val = p[2];
    if (p[2] == s->_val) {
        float r = randf__Fv();
        int id;
        if (r < p[3])
            id = 0x1b4e;
        else if (r < p[3])
            id = 0x1b4f;
        else if (r < p[3])
            id = 0x1b50;
        else
            id = 0x1b51;
        playSE__14snd3DGeneratorF5SndIDiii(&s->_se, id, 0, 0, -1);
        s->_val = p[4] + p[4] * randf__Fv();
    }
}
