
#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef struct 
{
  u32 len;
  u8 *data;
  u16 id;
  u8 type;
} Attr;
typedef struct 
{
  u32 handle;
  u32 used;
  u16 count;
  u16 pad;
  Attr attrs[25];
  u8 data[352];
} Record;
extern u8 lbl_8052D9C0[];
s32 fn_80257AB4(u32 handle)
{
  u16 i;
  u16 j;
  Record *rec = (Record *) (lbl_8052D9C0 + 0x1224);
  Record *new_var;
  if ((handle == 0) || ((*((u16 *) (lbl_8052D9C0 + 0x1222))) == 0))
  {
    *((u16 *) (lbl_8052D9C0 + 0x1222)) = 0;
    *((u32 *) (lbl_8052D9C0 + 0x121c)) = 0;
    lbl_8052D9C0[0x1220] = 0;
    return 1;
  }
  for (i = 0; i < (*((u16 *) (lbl_8052D9C0 + 0x1222))); i++, rec++)
  {
    if (rec->handle == handle)
    {
      for (; i < (*((u16 *) (lbl_8052D9C0 + 0x1222))); i++, rec++)
      {
        *rec = rec[1];
        new_var = rec;
        for (j = 0; j < new_var->count; j++)
        {
          rec->attrs[j].data = ((u8 *) new_var->attrs[j].data) - 0x298;
        }

      }

      *((u16 *) (lbl_8052D9C0 + 0x1222)) -= 1;
      if ((*((u32 *) (lbl_8052D9C0 + 0x121c))) == handle)
      {
        *((u32 *) (lbl_8052D9C0 + 0x121c)) = 0;
        lbl_8052D9C0[0x1220] = 0;
      }
      return 1;
    }
  }

  return 0;
}
