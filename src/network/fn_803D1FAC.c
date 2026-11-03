#pragma force_active on

extern float lbl_805A4A34;
extern float lbl_805A4A38;

void GXSetFog(int, unsigned char*, float, float, float, float);
void GXSetZMode(int, int, int);
void fn_801F471C(int);
void fn_801F4748(int);
void fn_801F48AC(int, int);
void fn_801F47D8(int, int);
void fn_801F1B2C(int, int, int, int);
void fn_801F1704(int);
void fn_801F1564(int, int, int, int);
void fn_801F15C8(int, int, void*, int);
void fn_801F1AB4(unsigned char*, unsigned int, unsigned char, unsigned char, unsigned char);
void fn_801D76BC(void*, unsigned int);
void fn_801F1E60(void*, unsigned char);
void fn_801F0AF0(void);

void fn_803D1FAC(void* arg0, int arg1, int arg2, int arg3, unsigned char* arg4)
{
    unsigned char buf[8];
    unsigned char a;
    unsigned char b;
    unsigned char c;
    unsigned char d;

    *(int*)(buf + 4) = 0;
    GXSetFog(0, buf + 4, lbl_805A4A34, lbl_805A4A34, lbl_805A4A38, lbl_805A4A38);
    fn_801F471C(1);
    fn_801F4748(1);
    fn_801F48AC(0, 0);
    GXSetZMode(1, 3, 1);
    fn_801F47D8(1, 0);
    fn_801F1B2C(0, 0, 0, 0);
    fn_801F1704(3);
    fn_801F1564(0, 0, arg1, arg2);
    fn_801F15C8(arg1, arg2, arg0, 0);
    a = arg4[0];
    b = arg4[1];
    c = arg4[2];
    d = arg4[3];
    buf[0] = a;
    buf[1] = b;
    buf[2] = c;
    buf[3] = d;
    fn_801F1AB4(buf, 0xFFFFFF, c, b, a);
    fn_801D76BC((void*)arg3, arg2 * ((arg1 * 2) & 0x1FFFE));
    fn_801F1E60((void*)arg3, 1);
    fn_801F0AF0();
}
