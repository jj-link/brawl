#pragma force_active on
extern "C" {

struct unk {
    unsigned int a : 5;
    signed int b : 5;
    unsigned int c : 22;
};

int fn_27_1CFD54(void* obj) {
    return ((unk*)((char*)obj + 8))->b;
}

}
