#pragma force_active on
extern "C" int fn_27_8D3E4(void*);

struct Part {
    char pad[0x88];
    char data[0x21AC];
};

struct Object {
    char pad[0x20];
    Part parts[3];

    Part* get(int i) {
        if (i == 2) return &parts[2];
        if (i == 1) return &parts[1];
        if (i == 0) return &parts[0];
        return 0;
    }
};

extern "C" void fn_27_3AEE00(Object* self) {
    for (int i = 0; i < 3; i++) {
        if (fn_27_8D3E4(self->get(i)->data) == 0)
            break;
    }
}
