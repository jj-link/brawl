#pragma force_active on
extern "C" void fn_27_72020(void*, unsigned short*, unsigned short*);

extern "C" void fn_27_71320(void* arg0, unsigned short* arg1) {
    struct Slot {
        unsigned short value;
        unsigned short pad;
    };
    Slot slots[6];

    slots[5].value = 2;
    fn_27_72020(arg0, &slots[5].value, arg1);

    slots[4].value = 1;
    fn_27_72020(arg0, &slots[4].value, arg1);

    slots[3].value = 4;
    fn_27_72020(arg0, &slots[3].value, arg1);

    slots[2].value = 8;
    fn_27_72020(arg0, &slots[2].value, arg1);

    slots[1].value = 0x20;
    fn_27_72020(arg0, &slots[1].value, arg1);

    slots[0].value = 0x10;
    fn_27_72020(arg0, &slots[0].value, arg1);
}
