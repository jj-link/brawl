
#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct Callbacks
{
  char pad[0x10];
  void (*event10)(u16, u16 *);
  void (*event14)(u16, u16 *);
  void (*event18)(unsigned int, int);
  char pad1c[8];
  void (*event24)(u16, u16 *);
} Callbacks;
typedef struct Object
{
  char pad0[4];
  int state;
  char pad8[12];
  u16 id;
  char pad16[2];
  char timer[0x18];
  Callbacks *callbacks;
  u8 flag;
  char pad35[0x3b];
  char data[1];
} Object;
extern u8 lbl_8052CDC0[];
extern char jumptable_80483008[];
extern void fn_802319FC(int, char *, int);
extern void fn_80231A14(int, char *, int, int);
extern void fn_80231FB0(void *, int, int);
extern void fn_80232020(void *);
extern void fn_8022F0E0(void *);
extern void fn_8022F500(void *, void *);
extern void fn_8024C208(void *, void *);
extern void fn_8024EC80(void *, u16 *);
extern void fn_8024EF78(void *, u16 *);
extern void fn_8024F424(void *);
extern void fn_8024FA74(void *);
extern u8 fn_8024FD88(void *, u16 *);
extern void fn_8024FED0(void *, u16 *);
extern void fn_8024FF10(void *, u16 *);
extern void fn_80250020(void *, u16 *);
void fn_8024B8A4(Object *obj, int event, void *arg)
{
  u8 level = lbl_8052CDC0[0];
  void *packet;
  Callbacks *callbacks = *((Callbacks **) (((char *) obj) + 0x30));
  void (*callback)(unsigned int, int) = *((void (**)(unsigned int, int)) (((char *) callbacks) + 0x18));
  char *base = jumptable_80483008;
  unsigned int id = (packet = arg, *((u16 *) (((char *) obj) + 0x14)));
  if (4U <= level)
  {
    fn_802319FC(0x80003, base + 0x494, event);
  }
  switch (event)
  {
    case 3:
      if (lbl_8052CDC0[0] >= 3)
    {
      fn_802319FC(0x80002, base + 0x40, obj->id);
    }
      fn_8024FA74(obj);
      callback(id, 0);
      break;

    case 14:
      if (fn_8024FD88(obj, packet))
    {
      if (lbl_8052CDC0[0] >= 3)
      {
        fn_802319FC(0x80002, base + 0x4b0, obj->id);
      }
      obj->callbacks->event10(obj->id, packet);
    }
    else
    {
      fn_8024EF78(obj, packet);
    }
      break;

    case 15:
      fn_8024FED0(obj, packet);
      obj->flag |= 2;
      if (obj->flag & 1)
    {
      obj->state = 6;
      fn_80232020(obj->timer);
      fn_8024C208(obj, 0);
    }
      if (lbl_8052CDC0[0] >= 3)
    {
      fn_802319FC(0x80002, base + 0x4e0, obj->id);
    }
      obj->callbacks->event14(obj->id, packet);
      break;

    case 16:
      fn_80232020(obj->timer);
      if (lbl_8052CDC0[0] >= 3)
    {
      fn_80231A14(0x80002, base + 0x510, obj->id, *((u16 *) packet));
      packet = arg;
    }
      obj->callbacks->event14(obj->id, packet);
      break;

    case 17:
      fn_80231FB0(obj->timer, 3, 30);
      obj->state = 8;
      if (lbl_8052CDC0[0] >= 3)
    {
      fn_802319FC(0x80002, base + 0x54c, obj->id);
    }
      obj->callbacks->event18(obj->id, 1);
      break;

    case 23:
      fn_8024FF10(obj, packet);
      fn_8024EC80(obj, packet);
      fn_80231FB0(obj->timer, 3, 30);
      break;

    case 24:
      fn_80250020(obj, packet);
      obj->flag |= 1;
      if (obj->flag & 2)
    {
      obj->state = 6;
      fn_80232020(obj->timer);
      fn_8024C208(obj, 0);
    }
      fn_8024EF78(obj, packet);
      break;

    case 25:
      fn_8024EF78(obj, packet);
      fn_80231FB0(obj->timer, 3, 30);
      break;

    case 26:
      fn_8024F424(obj);
      obj->state = 7;
      fn_80231FB0(obj->timer, 3, 30);
      break;

    case 19:
      if (lbl_8052CDC0[0] >= 3)
    {
      fn_802319FC(0x80002, base + 0x58c, obj->id);
    }
      obj->callbacks->event24(obj->id, packet);
      break;

    case 29:
      if (obj->flag & 2)
    {
      fn_8022F500(obj->data, packet);
    }
    else
    {
      fn_8022F0E0(packet);
    }
      break;

    case 30:
      fn_8024F424(obj);
      if (lbl_8052CDC0[0] >= 3)
    {
      fn_802319FC(0x80002, base + 0x40, obj->id);
    }
      fn_8024FA74(obj);
      callback(id, 0);
      break;

  }

}
