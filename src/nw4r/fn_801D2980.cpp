#pragma force_active on
struct Entry { int field0, field4, field8; void* fieldC; };
extern "C" {
int fn_801B8F4C(void*, unsigned int, unsigned int);
void fn_802022DC(int, int);
}
extern "C" void fn_801D2980(void* arg0, unsigned int arg1, int arg2) {
    int value = arg2;
    int i;
    int flag;
    char* ptr;
    flag = false;
    ptr = (char*)arg0;
    i = 0;
    for (; i < *(int*)((char*)arg0 + 0x9C); i++) {
        void* item = *(void**)(ptr + 0xC);
        if (item && fn_801B8F4C(item, arg1, value)) {
            flag = true;
            break;
        }
        ptr += 16;
    }
    if (flag) {
        if (*(unsigned char*)((char*)arg0 + 0xAE)) {
            char* inner;
            char* outer;
            int j;
            int i2;
            outer = (char*)arg0;
            for (i2 = 0; i2 < *(int*)((char*)arg0 + 0x9C); i2++) {
                inner = outer;
                for (j = 0; j < *(int*)((char*)arg0 + 0xA0); j++) {
                    void* fc2 = *(void**)(inner + 0xC);
                    if (fc2) {
                        char* obj = (char*)*(void**)fc2;
                        int match = 0;
                        if (obj && *(unsigned short*)(obj + 0x38) == 1)
                            match = 1;
                        if (match)
                            fn_802022DC((int)obj, 0);
                    }
                    inner += 4;
                }
                outer += 16;
            }
            *(unsigned char*)((char*)arg0 + 0xAE) = 0;
        }
        void (*cb)(void*, int, int) = *(void(**)(void*, int, int))((char*)arg0 + 0xA4);
        *(unsigned char*)((char*)arg0 + 0xB0) = 0;
        *(unsigned char*)((char*)arg0 + 0xAF) = 0;
        *(unsigned char*)((char*)arg0 + 0xAD) = 0;
        if (cb)
            cb(arg0, 1, *(int*)((char*)arg0 + 0xA8));
    }
}