#pragma force_active on
extern "C" int fn_8015C1EC(char* arg0, int arg1) {
    int var6 = 0;
    int var5 = 0;
    while (var5 = (var5 == 0) ? *(int*)arg0 : *(int*)(var5 + *(unsigned short*)(arg0 + 0xA) + 4)) {
        if (arg1 == var6) {
            return var5;
        }
        var6++;
    }
    return 0;
}
