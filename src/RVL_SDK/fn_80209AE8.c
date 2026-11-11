
#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
struct Node;
typedef void (*NodeFn)(struct Node *node);
struct Node
{
  s32 state;
  s32 b;
  s32 c;
  char pad0C[0x1C];
  NodeFn f28;
  NodeFn f2C;
  NodeFn f30;
  NodeFn f34;
  struct Node *next;
  struct Node *prev;
};
extern void fn_801D81F4();
extern void fn_801D7FCC(void *p);
extern s32 fn_8020981C(void);
extern s32 fn_8020982C(void);
extern s32 fn_8020983C(void);
extern void fn_80209850(u32 arg0);
extern void fn_80209F1C(void *a, void *b);
extern void fn_8020A2E8(void *node);
extern s32 lbl_805A0B80;
extern struct Node *lbl_805A0B84;
extern struct Node *lbl_805A0B8C;
extern struct Node *lbl_805A0B90;
extern struct Node *lbl_805A0B94;
void fn_80209AE8(void *unused, void *arg1)
{
  u8 sp8[0x2c8];
  u16 r5;
  s32 var;
  NodeFn fn;
  r5 = *((u16 *) (0xCC00500A & 0xFFFFFFFFFFFFFFFFu));
  *((u16 *) 0xCC00500A) = (r5 & (-0x29)) | 0x80;
  fn_801D81F4(sp8, arg1);
  fn_801D7FCC(sp8);
  do
  {
  }
  while (fn_8020982C() == 0);
  var = fn_8020983C();
  if ((lbl_805A0B94->c & 2) && ((((u32) var) + 0x232F0000) == 2))
  {
    var = 0xDCD10003;
  }
  switch (var)
  {
    case 0xDCD10000:
      lbl_805A0B94->state = 1;
      fn = lbl_805A0B94->f28;
      if (fn != 0)
    {
      fn(lbl_805A0B94);
    }
      break;

    case 0xDCD10001:
      lbl_805A0B94->state = 1;
      fn = lbl_805A0B94->f2C;
      if (fn != 0)
    {
      fn(lbl_805A0B94);
    }
      break;

    case 0xDCD10002:
      if (lbl_805A0B80 != 0)
    {
      if (lbl_805A0B94 == lbl_805A0B84)
      {
        fn_80209850(0xCDD10003);
        do
        {
        }
        while (fn_8020981C() != 0);
        lbl_805A0B84 = (void *) 0;
        lbl_805A0B80 = 0;
        fn = lbl_805A0B94->f2C;
        if (fn != 0)
        {
          fn(lbl_805A0B94);
        }
      }
      else
      {
        fn_80209850(0xCDD10001);
        do
        {
        }
        while (fn_8020981C() != 0);
        fn_80209F1C(lbl_805A0B94, lbl_805A0B84);
        lbl_805A0B94->state = 2;
        lbl_805A0B94 = lbl_805A0B84;
        lbl_805A0B80 = 0;
        lbl_805A0B84 = (void *) 0;
      }
    }
    else
      if (lbl_805A0B94->next == 0)
    {
      if (lbl_805A0B94 == lbl_805A0B90)
      {
        fn_80209850(0xCDD10003);
        do
        {
        }
        while (fn_8020981C() != 0);
        fn = lbl_805A0B94->f2C;
        if (fn != 0)
        {
          fn(lbl_805A0B94);
        }
      }
      else
      {
        fn_80209850(0xCDD10001);
        do
        {
        }
        while (fn_8020981C() != 0);
        fn_80209F1C(lbl_805A0B94, lbl_805A0B90);
        lbl_805A0B94->state = 2;
        lbl_805A0B94 = lbl_805A0B90;
      }
    }
    else
    {
      fn_80209850(0xCDD10001);
      do
      {
      }
      while (fn_8020981C() != 0);
      fn_80209F1C(lbl_805A0B94, lbl_805A0B94->next);
      lbl_805A0B94->state = 2;
      lbl_805A0B94 = lbl_805A0B94->next;
    }
      break;

    case 0xDCD10003:
      if (lbl_805A0B80 != 0)
    {
      if (lbl_805A0B94 != lbl_805A0B84)
      {
        fn = lbl_805A0B94->f30;
        if (fn != 0)
        {
          fn(lbl_805A0B94);
        }
        fn_80209850(0xCDD10001);
        do
        {
        }
        while (fn_8020981C() != 0);
        fn_80209F1C(0, lbl_805A0B84);
        fn_8020A2E8(lbl_805A0B94);
        lbl_805A0B94 = lbl_805A0B84;
        lbl_805A0B80 = 0;
        lbl_805A0B84 = (void *) 0;
        break;
      }
      lbl_805A0B84 = (void *) 0;
      lbl_805A0B80 = 0;
    }
      if (lbl_805A0B94->next == 0)
    {
      if (lbl_805A0B94 == lbl_805A0B90)
      {
        fn = lbl_805A0B94->f30;
        if (fn != 0)
        {
          fn(lbl_805A0B94);
        }
        fn_80209850(0xCDD10002);
        do
        {
        }
        while (fn_8020981C() != 0);
        lbl_805A0B94->state = 3;
        fn_8020A2E8(lbl_805A0B94);
      }
      else
      {
        fn = lbl_805A0B94->f30;
        if (fn != 0)
        {
          fn(lbl_805A0B94);
        }
        fn_80209850(0xCDD10001);
        do
        {
        }
        while (fn_8020981C() != 0);
        lbl_805A0B94->state = 3;
        fn_80209F1C(0, lbl_805A0B90);
        lbl_805A0B94 = lbl_805A0B90;
        fn_8020A2E8(lbl_805A0B8C);
      }
    }
    else
    {
      fn = lbl_805A0B94->f30;
      if (fn != 0)
      {
        fn(lbl_805A0B94);
      }
      fn_80209850(0xCDD10001);
      do
      {
      }
      while (fn_8020981C() != 0);
      lbl_805A0B94->state = 3;
      fn_80209F1C(0, lbl_805A0B94->next);
      lbl_805A0B94 = lbl_805A0B94->next;
      fn_8020A2E8(lbl_805A0B94->prev);
    }
      break;

    case 0xDCD10004:
      fn = lbl_805A0B94->f34;
      if (fn != 0)
    {
      fn(lbl_805A0B94);
    }
      break;

  }

  fn_801D81F4(sp8);
  fn_801D7FCC(arg1);
}
