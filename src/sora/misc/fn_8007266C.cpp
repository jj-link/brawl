#pragma force_active on
extern "C" {

extern char lbl_804543D8[];

void fn_8007266C(void* p) {
    ((void**)p)[0] = &lbl_804543D8;
    ((int*)p)[9] = 0;
    ((int*)p)[10] = 0;
    ((int*)p)[11] = 0;
    ((int*)p)[12] = 0;
    ((int*)p)[13] = 0;
    ((int*)p)[14] = 0;
    ((int*)p)[15] = 0;
    ((char*)p)[0x40] = 1;
    ((char*)p)[0x41] = 0;
}

}
