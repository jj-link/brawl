#pragma force_active on
extern "C" {
void* getInstance__14gfSceneManagerFv();
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_1_385C(int);
extern char lbl_9_data_268[];
extern char lbl_9_data_298[];

void* fn_9_34F0(void* self) {
    char* s = (char*)self;
    int flag = 0;
    int c = *(int*)(s + 0x17EC) - 1;
    *(int*)(s + 0x17EC) = c;
    if (c >= 0) {
        return *(void**)(s + 0x1A0);
    }
    if (*(unsigned char*)(s + 0x17E9) != 0) {
        if (fn_1_385C(0) != 0) {
            flag = 1;
        }
    } else {
        flag = 1;
    }
    if (flag != 0) {
        char* m = (char*)getInstance__14gfSceneManagerFv();
        __dynamic_cast(*(void**)(m + 4), 4, lbl_9_data_268, lbl_9_data_298, 0);
        m = (char*)getInstance__14gfSceneManagerFv();
        *(int*)(m + 0x284) = 1;
        *(int*)(m + 0x288) = 2;
    }
    return *(void**)(s + 0x1A0);
}
}
