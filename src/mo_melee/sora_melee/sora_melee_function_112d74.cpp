#pragma force_active on
typedef unsigned char u8;

struct Obj {
    u8 pad[0x1f];
    u8 pad2 : 7;
    u8 flag : 1;
};

extern "C" {
bool fn_27_112D74(Obj** self)
{
    return (*self)->flag != 0;
}
}
