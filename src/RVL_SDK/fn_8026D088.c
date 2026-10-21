#pragma force_active on
typedef unsigned char u8;

void fn_8026D0E0(void);
void fn_8026D244(void);
void fn_8026D3A8(void);

void fn_8026D088(u8* obj) {
    int v = obj[0];
    switch (v) {
    case 0:
        *(void**)(obj + 0x24) = (void*)fn_8026D0E0;
        break;
    case 2:
        *(void**)(obj + 0x24) = (void*)fn_8026D244;
        break;
    case 1:
        *(void**)(obj + 0x24) = (void*)fn_8026D3A8;
        break;
    }
}
