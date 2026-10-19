#pragma force_active on
struct Color {
    unsigned char r, g, b, a;
};

extern "C" {
extern unsigned char lbl_40_data_BE30[];
extern Color lbl_40_rodata_560;
extern Color lbl_40_rodata_564;

void fn_27_26C78C(void*, void*, void*, Color*, void*);
void fn_27_26C65C(void*, void*, void*, Color*, void*);

void fn_40_2EC24(void* obj) {
    unsigned char* self = (unsigned char*)obj;
    unsigned char* data = lbl_40_data_BE30;

    if (self[0x16c] == 1) {
        Color a = lbl_40_rodata_560;
        Color b = lbl_40_rodata_564;

        fn_27_26C78C(obj, data + 0x28, data + 0x10, &a, data + 0x2c);
        fn_27_26C65C(obj, data + 0x30, data + 0x1c, &b, data + 0x34);

        self[0x16c] = 0;
    }
}
}
