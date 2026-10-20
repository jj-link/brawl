#pragma force_active on
struct Field3 {
    int a : 6;
    int v : 3;
    int b : 23;
};

extern "C" void fn_51_DA9C(void* param, int value) {
    ((Field3*)((char*)param + 8))->v = value;
}
