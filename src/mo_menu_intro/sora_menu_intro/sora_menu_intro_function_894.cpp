#pragma force_active on

extern "C" {
void* getInstance__14gfSceneManagerFv();
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern char lbl_13_data_188[];
extern char lbl_13_data_1B8[];

void fn_13_894(void* self) {
    void* mgr = getInstance__14gfSceneManagerFv();
    void* casted = __dynamic_cast(*(void**)((char*)mgr + 4), 4, lbl_13_data_188, lbl_13_data_1B8, 0);
    char* s = (char*)casted;
    char* d = (char*)self;
    *(int*)(d + 0xac) = *(int*)(s + 0x35c);
    *(int*)(d + 0xb0) = *(int*)(s + 0x360);
    *(int*)(d + 0xb4) = *(int*)(s + 0x364);
    *(int*)(d + 0xd0) = *(int*)(s + 0x380);
    *(int*)(d + 0xb8) = *(int*)(s + 0x368);
    *(int*)(d + 0xbc) = *(int*)(s + 0x36c);
    *(int*)(d + 0xc0) = *(int*)(s + 0x370);
    *(int*)(d + 0xc4) = *(int*)(s + 0x374);
    *(int*)(d + 0xc8) = *(int*)(s + 0x378);
    *(int*)(d + 0xcc) = *(int*)(s + 0x37c);
    *(int*)(d + 0xd4) = *(int*)(s + 0x384);
    *(int*)(d + 0xd8) = *(int*)(s + 0x388);
    *(int*)(d + 0xdc) = *(int*)(s + 0x38c);
    *(int*)(d + 0xe0) = *(int*)(s + 0x390);
}
}
