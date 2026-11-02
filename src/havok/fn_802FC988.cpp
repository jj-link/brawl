#pragma force_active on
extern "C" {
extern const float lbl_805A4560;
}

typedef void (*EntryFunc)(void*, void*, void*, float, float);

extern "C" void fn_802FC988(void*** arg0, void** arg1, float farg1, float farg2) {
    float neg = lbl_805A4560;
    int idx = 4;
    unsigned char* blk = (unsigned char*)**arg0;
    unsigned char* entry = blk + 0x10;
    unsigned char* end = (unsigned char*)((int)blk + *(int*)blk + 0x10);

    for (;;) {
        unsigned char* e = entry;
        unsigned char* dat;
        EntryFunc fn;

        switch (e[0]) {
        case 2:
        case 3:
        case 6:
            dat = entry + 0x10;
            entry += e[3];
            fn = *(EntryFunc*)((char*)*arg1 + e[1] * 0x34 + 0x16b4);
            if (fn != 0) {
                fn(e, dat, arg1, farg1, farg2);
            }
            break;
        case 4:
        case 5:
            dat = entry + 0x20;
            if (*(float*)(e + 0xc) == farg1) {
                *(float*)(e + 0xc) = farg2;
            } else {
                *(float*)(e + 0xc) = neg;
            }
            entry += e[3];
            fn = *(EntryFunc*)((char*)*arg1 + e[1] * 0x34 + 0x16b4);
            if (fn != 0) {
                fn(e, dat, arg1, farg1, farg2);
            }
            break;
        case 1:
            goto done;
        case 0:
            entry += e[3];
            break;
        }

        if (entry >= end) {
            blk = (unsigned char*)*(void**)((char*)*arg0 + idx);
            idx += 4;
            entry = blk + 0x10;
            blk += *(int*)blk;
            end = blk + 0x10;
        }
    }
done:
    return;
}
