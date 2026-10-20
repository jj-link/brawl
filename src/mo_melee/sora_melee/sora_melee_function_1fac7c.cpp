#pragma force_active on
extern "C" int fn_27_1F2CBC(signed char* p);

extern "C" void fn_27_1FAC7C(unsigned char* self, int flag) {
    if (fn_27_1F2CBC((signed char*)(self + 0x42)) <= 0) {
        self[0x41] = self[0x110];
        if (flag != 0 && self[0x40] == 0) {
            self[0x40] = 1;
        }
    }
}
