#pragma force_active on

extern "C" {
void fn_18_17B0(void*, int, int, float);
void fn_18_18D4(void*, unsigned, unsigned, float);
}

extern "C" void fn_2_2CA88(char* self) {
    float seed0 = 0.0625f;
    float seed1 = 0.0f;
    float seed2 = 3.0f;
    float seed3 = 4.0f;
    float seed4 = 1.0f;
    float seed5 = 9.0f;
    double seed6 = 4503599627370496.0;
    switch (*reinterpret_cast<int*>(self + 0x688)) {
    case 0: fn_18_18D4(self, 0xbe, 1, 1.0f); break;
    case 1: fn_18_18D4(self, 0xbe, 1, 0.5f); break;
    case 2: fn_18_18D4(self, 0xbe, 1, 2.0f); break;
    }
    fn_18_17B0(self, 0xbf, 2, (float)*reinterpret_cast<unsigned int*>(self + 0x67c));
    fn_18_17B0(self, 0xbf, 1, (float)*reinterpret_cast<unsigned int*>(self + 0x674));
    switch (*reinterpret_cast<int*>(self + 0x670)) {
    case 0: fn_18_17B0(self, 0xc0, 2, 0.0f); break;
    case 1: fn_18_17B0(self, 0xc0, 2, 2.0f); break;
    case 2: fn_18_17B0(self, 0xc0, 2, 1.0f); break;
    }
    fn_18_17B0(self, 0xc1, 2, (float)*reinterpret_cast<unsigned int*>(self + 0x678));
    fn_18_17B0(self, 0xc2, 2, (float)*reinterpret_cast<unsigned int*>(self + 0x680));
}
