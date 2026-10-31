#pragma force_active on
extern "C" {

extern unsigned char lbl_10_rodata_84C[];
extern void* fn_10_19FF4(void*, int, int);

void* fn_10_1B488(void* obj, int a, int b) {
    int result;
    if (b == 8) {
        result = 5;
    } else if (a == 1) {
        if (*(int*)((char*)obj + 0xa0))
            result = 7;
        else if (b == 1)
            result = 3;
        else
            result = 2;
    } else {
        result = 1;
        const unsigned char* p = lbl_10_rodata_84C;
        for (int i = 0; i < 3; i++) {
            if (b == *p) {
                result = *(lbl_10_rodata_84C + i * 2 + 1);
                break;
            }
            p += 2;
        }
    }
    if (result == *(int*)((char*)obj + 0x80))
        return obj;
    return fn_10_19FF4(obj, result, 0);
}

}