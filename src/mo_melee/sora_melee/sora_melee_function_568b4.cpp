#pragma force_active on
class Class_5860 {
public:
    virtual void fn_27_565F0();
    virtual void fn_27_56888();
    virtual unsigned int fn_27_5680C(unsigned int, unsigned int);
};
struct Context {
    unsigned char pad[0x34];
    unsigned int field34;
    unsigned char pad38[4];
    void* field3C;
    unsigned int field40;
    Class_5860* field44;
    unsigned char pad48[8];
    float field50;
    unsigned int field54;
};
extern "C" int fn_27_58120(void*, int, unsigned int, int, int);
extern "C" void fn_800778CC(void*, int, float);
extern void* g_sndSystem;
extern const float lbl_27_rodata_728;
static inline int play(Context* self, int value, unsigned int id, unsigned int mode) {
    if (mode == 1)
        return fn_27_58120(self->field3C, value, id, -1, self->field54);
    return fn_27_58120(self->field3C, value, id, self->field34, self->field54);
}
extern "C" int fn_27_568B4(Context* self, unsigned int param1, unsigned int param2, unsigned int param3, int param4) {
    unsigned int id = self->field44->fn_27_5680C(param1, self->field40);
    if (id == 0xFFFFFFFF)
        return -1;
    int result = play(self, param4, id, param3);
    if (lbl_27_rodata_728 != self->field50 && param2 == 1 && result >= 0)
        fn_800778CC(g_sndSystem, result, self->field50);
    return result;
}