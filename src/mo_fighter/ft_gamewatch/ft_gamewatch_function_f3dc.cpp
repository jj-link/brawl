#pragma force_active on

extern "C" {
void fn_107_F618(short* dst, const short* src);
void fn_107_FD64(short* dst, const short* src);
void fn_107_FCCC(void* object, const short* operation, void* argument);
void fn_107_FBE4(void* object, const short* input, void* argument);
void fn_107_FAFC(void* object, const short* operation, void* argument);
void fn_107_FA14(void* object, const short* operation, void* argument);
void fn_107_F92C(unsigned char* self, const short* p, void* arg);
void fn_107_F844(void* self, short* source, void* arg);
void fn_107_F75C(void* self, const short* p, void* arg);
void fn_107_F674(void* self, const short* p, void* arg);
}

extern "C" void fn_107_F3DC(unsigned char* object, void* argument, const short* index) {
    short operation;
    short value = *index;
    short second, fourth, sixth, eighth;
    short seventh, fifth, third, first;

    fn_107_F618(&operation, &value);
    fn_107_FD64(&first, &operation);
    fn_107_FCCC(object + 0x208, &first, argument);
    fn_107_FD64(&second, &operation);
    fn_107_FBE4(object + 0x1CC, &second, argument);
    fn_107_FD64(&third, &operation);
    fn_107_FAFC(object + 0x180, &third, argument);
    fn_107_FD64(&fourth, &operation);
    fn_107_FA14(object + 0x138, &fourth, argument);
    fn_107_FD64(&fifth, &operation);
    fn_107_F92C(object + 0xF0, &fifth, argument);
    fn_107_FD64(&sixth, &operation);
    fn_107_F844(object + 0x98, &sixth, argument);
    fn_107_FD64(&seventh, &operation);
    fn_107_F75C(object + 0x64, &seventh, argument);
    fn_107_FD64(&eighth, &operation);
    fn_107_F674(object + 8, &eighth, argument);
}
