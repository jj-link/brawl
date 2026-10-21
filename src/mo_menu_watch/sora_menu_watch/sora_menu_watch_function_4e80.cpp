#pragma force_active on

extern "C" int isReady__14gfFileIOHandleCFv(const void*);

extern "C" int fn_15_4E80(char* self) {
    int i = 0;
    int st;
    int ready;
    char* p = self + 0x254;

    for (; i < 0x28; i++) {
        if (*(int*)(p + 4) != 0) {
            st = 2;
        } else if (!((((unsigned char)p[0]) >> 7) & 1)) {
            st = 0;
        } else {
            int r = isReady__14gfFileIOHandleCFv(p + 8);
            st = 1;
            if (r != 0) {
                st = 2;
            }
        }

        if (st == 1) {
            ready = 0;
            goto done;
        }
        p += 0xc;
    }
    ready = 1;

done:
    if (ready != 0) {
        return 0xc;
    }
    return *(int*)(self + 0x504);
}
