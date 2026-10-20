#pragma force_active on
typedef struct {
    unsigned int w0;
    unsigned int w1;
    unsigned int pad0 : 2;
    unsigned int f : 2;
    unsigned int rest : 28;
} FlagWord;

extern "C" void fn_47_4C68(FlagWord *obj, unsigned int val) {
    obj->f = val;
}
