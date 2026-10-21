#pragma force_active on
extern void fn_8024C918(void* a);
extern void fn_8024AED0(void* a, int b, int c);
extern void fn_8024E43C(int a);

void fn_8024E3EC(void* self) {
    unsigned short val = *(unsigned short*)((char*)self + 0x14);
    switch (val) {
        case 2:
            fn_8024C918(*(void**)((char*)self + 0x10));
            break;
        case 3:
            fn_8024AED0(*(void**)((char*)self + 0x10), 0x1e, 0);
            break;
        case 4:
            fn_8024E43C(1);
            break;
        case 0x49:
            break;
        default:
            break;
    }
}
