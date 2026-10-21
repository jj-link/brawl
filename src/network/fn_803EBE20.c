#pragma force_active on
typedef void FAHandle;

int fn_803EB5D8(void);

int FAClosedir(FAHandle* handle) {
    int err = fn_803EB5D8();
    return (-err | err) >> 0x1F;
}
