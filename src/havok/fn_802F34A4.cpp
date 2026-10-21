extern "C" int fn_80300488(char* a, char* b);
extern "C" void fn_802F3670();

struct Pair {
    char* unk0;
    char* unk4;
};

#pragma force_active on
extern "C" void fn_802F34A4(void* unused, Pair* arg1) {
    char* temp_r5 = arg1->unk0;
    char* temp_r4 = arg1->unk4;
    if (fn_80300488(temp_r5 + (signed char)temp_r5[5], temp_r4 + (signed char)temp_r4[5]) != 0) {
        fn_802F3670();
    }
}
