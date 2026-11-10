#pragma force_active on

typedef unsigned char u8;
typedef struct State
{
  char pad0[0x5ec];
  char queue[0x2b4];
  void (*callback)(int, int);
  char pad8a4[0x1d];
  u8 type;
  u8 other;
  char pad8c3[0x51];
  u8 a[6];
  u8 b[6];
  u8 c[4];
  char pad924[0x10];
  char data[0x40];
  u8 *input;
  char pad978[0x15];
  u8 mode;
} State;
extern State *lbl_804F6810[];
extern char lbl_8047C920[];
extern u8 lbl_805A0C8C[4];
extern u8 lbl_805A0C90[4];
extern u8 lbl_805A0C94[4];
extern int lbl_805A0630;
extern void fn_8022550C(void *, ...);
extern void fn_8021E47C(int, int);
extern int fn_8021DE7C(void *, int, unsigned int, void (*)(int, int));
extern int fn_8021E030(void *, void *, unsigned short, unsigned int, void (*)(int, int));
extern int fn_8021E1E8(void *, void *, unsigned short, unsigned int, void (*)(int, int));
extern void fn_8022391C(int);
extern void fn_8022400C(int);
void fn_8021F5A0(int channel, int result)
{
  char *base = lbl_8047C920;
  State *s = lbl_804F6810[channel];
  int new_var;
  u8 *p = s->input;
  char *queue = s->queue;
  u8 *type;
  if (result == 0)
  {
    fn_8022550C(base + 0x3d8, p[5], p[0]);
    lbl_805A0C8C[channel] = 0;
    lbl_805A0C90[channel] = p[4];
    switch (p[5])
    {
      case 0:
        lbl_805A0C94[channel] = 1;
        type = &lbl_805A0C94[channel];
        break;

      case 1:
        lbl_805A0C94[channel] = 2;
        type = &lbl_805A0C94[channel];
        break;

      case 3:
        if (lbl_805A0630)
      {
        type = &lbl_805A0C94[channel];
        new_var = (lbl_805A0C90[channel] = 1) + 1;
        *type = new_var;
        lbl_805A0C8C[channel] = lbl_805A0C90[channel];
      }
      else
      {
        lbl_805A0C94[channel] = 0xfb;
        type = &lbl_805A0C94[channel];
      }
        break;

      default:
        lbl_805A0C94[channel] = 0xfb;
        type = &lbl_805A0C94[channel];
        break;

    }

    if (((*type) == 2) && ((lbl_805A0C90[channel] < 1) || (lbl_805A0C90[channel] > 3)))
    {
      *type = 0xfc;
    }
    fn_8022550C(base + 0x3f0, *type);
    fn_8022550C(base + 0x3fc, lbl_805A0C90[channel]);
    if (((u8) ((*type) + 5)) <= 1)
    {
      s->type = *type;
      s->other = lbl_805A0C90[channel];
      if (s->callback)
      {
        s->callback(channel, s->type);
      }
    }
    else
      if (((u8) ((*type) + 255)) <= 1)
    {
      s->mode = 2;
      fn_8021DE7C(queue, 0xaa, 0x04a400f0, fn_8021E47C);
      fn_8022391C(channel);
      fn_8021E030(queue, s->a, 6, 0x04a40040, fn_8021E47C);
      fn_8021E030(queue, s->b, 6, 0x04a40046, fn_8021E47C);
      fn_8021E030(queue, s->c, 4, 0x04a4004c, fn_8021E47C);
      fn_8021E1E8(queue, s->data, 0x20, 0x04a40020, s->callback);
    }
    else
    {
      s->mode = 3;
      fn_8021DE7C(queue, 0xaa, 0x04a400f0, fn_8021E47C);
      fn_8022400C(channel);
      fn_8021E030(queue, s->a, 6, 0x04a40040, fn_8021E47C);
      fn_8021E030(queue, s->b, 6, 0x04a40046, fn_8021E47C);
      fn_8021E030(queue, s->c, 4, 0x04a4004c, fn_8021E47C);
      fn_8021E1E8(queue, s->data, 0x20, 0x04a40020, s->callback);
    }
  }
  else
  {
    s->type = 0xfc;
    s->other = 0;
  }
}
