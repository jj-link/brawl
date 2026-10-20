#pragma force_active on
extern "C" signed char getPlayerNumber__10grYakumonoFPi(void*, int*);
extern "C" const float lbl_40_rodata_750;

struct StageObject {
    unsigned char pad[0x154];
    unsigned char flag;
    unsigned char pad2[3];
    float value;
};

extern "C" void fn_40_38124(StageObject* self, int* playerPtr, int* resultPtr) {
    int player = *playerPtr;

    getPlayerNumber__10grYakumonoFPi(self, resultPtr);
    signed char result = getPlayerNumber__10grYakumonoFPi(self, resultPtr);

    if (result == 0 && player == 0x32) {
        self->flag = 1;
        self->value = lbl_40_rodata_750;
    }
}
