#pragma force_active on
struct Data {
    unsigned char pad[5];
    unsigned char active : 1;
    unsigned char rest : 7;
    unsigned char state;
};
extern "C" void fn_27_34D3FC(Data*, int);
extern "C" void fn_27_34CAA4(void* self, int arg) {
    Data* data = (Data*)((char*)self + 0x14);
    if ((bool)data->active == true && data->state == 0)
        fn_27_34D3FC(data, arg);
}
