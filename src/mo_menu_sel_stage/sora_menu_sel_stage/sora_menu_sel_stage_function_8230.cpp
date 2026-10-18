#pragma force_active on
extern "C" void fn_80039A04(void* p, int n);

struct SelObj {
    char pad[0x68];
    void* field;
};

extern "C" {
void fn_11_8230(SelObj* obj) {
    fn_80039A04(obj->field, 3);
}
}
