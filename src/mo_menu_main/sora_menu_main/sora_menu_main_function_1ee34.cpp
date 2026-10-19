#pragma force_active on
extern "C" int isCharUsable__6muMenuFiii(int);

extern "C" int fn_2_1EE34() {
    int i = 0;
    int count = 0;
    do {
        if (isCharUsable__6muMenuFiii(i)) ++count;
        ++i;
    } while (i < 0x23);
    return count;
}
