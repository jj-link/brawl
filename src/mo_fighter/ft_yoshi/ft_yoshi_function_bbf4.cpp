#pragma force_active on
extern "C" {
void fn_95_BAC8(void* out, void* arg1, void* arg2);

void* fn_95_BBF4(void* arg1, void* arg2) {
    unsigned char temp[0x18];
    fn_95_BAC8(temp, arg1, arg2);
    return temp;
}
}
