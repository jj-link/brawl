#pragma force_active on
typedef int s32;
typedef unsigned char u8;

s32 fn_803A75BC(s32, void *, s32, s32, u8 *);
extern s32 lbl_805A1044;

s32 recvfrom(s32 socket, void *buffer, s32 length, s32 flags, u8 *address, s32 *address_length) {
    s32 result;
    *address = (u8)*address_length;
    result = fn_803A75BC(socket, buffer, length, 4, address);
    *address_length = *address;
    if (result >= 0) {
        return result;
    }
    lbl_805A1044 = result;
    return -1;
}
