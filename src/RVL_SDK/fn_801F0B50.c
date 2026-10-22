#pragma force_active on
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 *__peReg;

typedef union {
    u32 word;
    struct {
        u32 tag : 8;
        u32 pad16 : 8;
        u32 op : 4;
        u32 subtract : 1;
        u32 src : 3;
        u32 dst : 3;
        u32 pad2 : 3;
        u32 logic : 1;
        u32 blend : 1;
    } bits;
} BlendReg;

void fn_801F0B50(int arg0, int arg1, int arg2, int arg3)
{
    u32 v;
    u32 flag = 0;

    v = __peReg[1];
    if (arg0 == 1 || arg0 == 3) {
        flag = 1;
    }
    ((BlendReg *)&v)->bits.blend = flag;
    ((BlendReg *)&v)->bits.subtract = arg0 == 3;
    ((BlendReg *)&v)->bits.logic = arg0 == 2;
    ((BlendReg *)&v)->bits.op = arg3;
    ((BlendReg *)&v)->bits.src = arg1;
    ((BlendReg *)&v)->bits.dst = arg2;
    ((BlendReg *)&v)->bits.tag = 0x41;
    __peReg[1] = (u16)v;
}
