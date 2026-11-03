#pragma force_active on

extern "C" {
int fn_800D1978(void*);
int fn_800D0AD8(void*);
void fn_8013FDD4(void*);
extern char lbl_27_data_52B78[];
extern char g_Network[];
extern void* g_muWifiInterfaceTask;
}

extern "C" int fn_27_254ED0(void* p) {
    unsigned char* self = (unsigned char*)p;
    char* d = lbl_27_data_52B78;
    if (self[0x49] != 0) {
        switch (*(int*)(self + 0x70)) {
        case 0:
            *(int*)(self + 0x6C) = *(int*)(d + 0xA0);
            *(int*)(self + 0x70) = 0x98;
            goto c1;
        l9c:
            *(int*)(self + 0x6C) = *(int*)(d + 0xA4);
            *(int*)(self + 0x70) = 0x9C;
            break;
        case 0x98:
        case 0x9C:
        c1:
            if (fn_800D1978(g_muWifiInterfaceTask) == 0) goto l9c;
            goto c2;
        la1:
            *(int*)(self + 0x6C) = *(int*)(d + 0xA8);
            *(int*)(self + 0x70) = 0xA1;
            break;
        case 0xA1:
        c2:
            if (fn_800D0AD8(g_muWifiInterfaceTask) == 0) goto la1;
            fn_8013FDD4(*(void**)(g_Network + 0x34));
            *(int*)(self + 0x6C) = *(int*)(d + 0xAC);
            *(int*)(self + 0x70) = 0xA6;
            break;
        }
        return *(int*)(self + 0x6C) == 2;
    }
    return 1;
}
