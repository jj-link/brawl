#pragma force_active on
extern "C" {

unsigned int fn_24_3174(void*, void*);

bool fn_24_30D8(void* param) {
    char* a = (char*)param;
    char* b = (char*)param + 0x100;
    for (int i = 0; i < 4; i++) {
        if (fn_24_3174(param, (void*)a) == 1)
            return true;
        if (fn_24_3174(param, (void*)b) == 1)
            return true;
        a += 0x40;
        b += 0x40;
    }
    return false;
}

}
