#pragma force_active on
struct Level2;

struct Level1 {
    char pad[0x15c];
    Level2* field_15c;
};

struct Level2 {
    char pad[0xc];
    void* field_c;
};

struct CollectViewerParam {
    char pad[0x1ac];
    Level1* field_1ac;
};

extern "C" {
void fn_8019D950(void*);
}

extern "C" void fn_6_683C(CollectViewerParam* param) {
    fn_8019D950(param->field_1ac->field_15c->field_c);
}
