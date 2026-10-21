#pragma force_active on

typedef signed short s16;
typedef unsigned int u32;

struct Manager {
    virtual s16 add(void*);
};

extern "C" {
void* getInstance__13soEventSystemFv();
Manager* getManager__13soEventSystemFl(void*, long);
char lbl_27_data_25F60[];
char lbl_27_data_18BC0[];
char lbl_27_data_21DA0[];
char lbl_27_data_21E98[];
void fn_27_EF1D4(void*);
void* fn_27_84218(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*, int),
                       unsigned long, unsigned long);
}

extern "C" void* fn_27_D7AE8(char* self, s16 id, s16 handle) {
    *(s16*)(self + 4) = id;
    *(void**)self = lbl_27_data_25F60;
    *(s16*)(self + 6) = handle;

    if (id != -1) {
        s16 result = getManager__13soEventSystemFl(
            getInstance__13soEventSystemFv(), *(s16*)(self + 4))->add(self);
        if (result > -1)
            *(s16*)(self + 6) = result;
    }

    char* inner = self + 12;
    *(void**)(self + 8) = inner;
    *(void**)self = lbl_27_data_18BC0;
    inner[4] = 0;
    *(void**)(inner + 0) = lbl_27_data_21DA0;
    *(void**)(inner + 8) = lbl_27_data_21DA0 + 0x34;
    *(void**)(inner + 12) = lbl_27_data_21DA0 + 0x40;
    *(void**)(inner + 16) = lbl_27_data_21E98;
    *(void**)(inner + 20) = lbl_27_data_21E98 + 0x48;
    *(u32*)(inner + 24) &= 0x3FFFFF;
    __construct_array(inner + 28, fn_27_EF1D4,
                      (void (*)(void*, int))fn_27_84218, 12, 2);
    inner[52] = 0;
    return self;
}
