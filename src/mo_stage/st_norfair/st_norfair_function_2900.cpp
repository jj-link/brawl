#pragma force_active on
extern "C" {
bool isEvent__13grTenganEventCFv(const void* self);
}

extern "C" int fn_54_2900(unsigned char* self, void* unused, int* p5, int* p6) {
    if (self[0x831] == 0) {
        return 0;
    }
    if (self[0x79a] != 0) {
        if (isEvent__13grTenganEventCFv(self + 0x6c8) == 0) {
            if (self[0x830] == 1) {
                *p5 = 7;
                *p6 = 4;
            } else {
                *p5 = 8;
                *p6 = 3;
            }
            return 1;
        }
    }
    return 0;
}
