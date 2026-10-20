#pragma force_active on
struct Offset8 {
    unsigned int pad : 15;
    unsigned int value : 1;
};

extern "C" int fn_27_D3788(void* self) {
    Offset8* o8 = (Offset8*)((char*)self + 8);
    return o8->value;
}
