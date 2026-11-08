#pragma force_active on
class soModuleAccesser;

extern "C" {
void fn_106_9C60(short* dst, const short* src);
void fn_106_A3AC(short* dst, const short* src);
void fn_106_A314(unsigned char* self, short* src, soModuleAccesser* accesser);
void fn_106_A22C(unsigned char* self, short* src, soModuleAccesser* accesser);
void fn_106_A144(unsigned char* self, short* src, soModuleAccesser* accesser);
void fn_106_A05C(unsigned char* self, short* src, soModuleAccesser* accesser);
void fn_106_9F74(unsigned char* self, short* src, soModuleAccesser* accesser);
void fn_106_9E8C(unsigned char* self, short* src, soModuleAccesser* accesser);
void fn_106_9DA4(unsigned char* self, short* src, soModuleAccesser* accesser);
void fn_106_9CBC(unsigned char* self, short* src, soModuleAccesser* accesser);
}

extern "C" void fn_106_9A24(unsigned char* object, soModuleAccesser* accesser, const short* index) {
    short operation;
    short value = *index;
    short second, fourth, sixth, eighth;
    short seventh, fifth, third, first;
    short ninth, tenth;

    fn_106_9C60(&operation, &value);
    fn_106_A3AC(&first, &operation);
    fn_106_A314(object + 0x208, &first, accesser);
    fn_106_A3AC(&second, &operation);
    fn_106_A22C(object + 0x1CC, &second, accesser);
    fn_106_A3AC(&third, &operation);
    fn_106_A144(object + 0x180, &third, accesser);
    fn_106_A3AC(&fourth, &operation);
    fn_106_A05C(object + 0x138, &fourth, accesser);
    fn_106_A3AC(&fifth, &operation);
    fn_106_9F74(object + 0xF0, &fifth, accesser);
    fn_106_A3AC(&sixth, &operation);
    fn_106_9E8C(object + 0x98, &sixth, accesser);
    fn_106_A3AC(&seventh, &operation);
    fn_106_9DA4(object + 0x64, &seventh, accesser);
    fn_106_A3AC(&eighth, &operation);
    fn_106_9CBC(object + 8, &eighth, accesser);
}
