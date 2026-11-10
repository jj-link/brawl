
#pragma force_active on
extern int fn_803CD270(void);
extern char **fn_803CD2A8(void);
extern int fn_803CD458(void);
extern int fn_803CD438(void);
extern void fn_803D4E0C(void *, void *);
extern int fn_803D5B90(void *);
extern void *memcpy(void *, const void *, unsigned long);
void *fn_803D4CB8(unsigned int index)
{
  struct 
  {
    char data[0x2e];
    char name[0x14];
    unsigned short end;
    char extra[0x10];
  } buffer;
  unsigned char *entry;
  unsigned char *new_var;
  char **p;
  int present;
  int *id;
  if (index >= 100)
  {
    return 0;
  }
  if (fn_803CD270() == 0)
  {
    return 0;
  }
  p = fn_803CD2A8();
  if (p == 0)
  {
    goto fail;
  }
  if (fn_803CD270() == 0)
  {
    entry = 0;
  }
  else
    if (fn_803CD2A8() == 0)
  {
    entry = 0;
  }
  else
  {
    entry = 0;
    if ((fn_803CD458() == 0) && (fn_803CD438() == 0))
    {
      entry = (unsigned char *) 1;
      if (p)
      {
      }
    }
  }
  if (!entry)
  {
    fail:
    return 0;

  }
  new_var = ((unsigned char *) (&(*p)[4])) + (index * 0x4a);
  entry = new_var;
  id = (int *) (entry + 0x18);
  if (id == 0)
  {
    present = 0;
  }
  else
  {
    present = 0;
    if ((id[0] != 0) || (id[1] != 0))
    {
      present = 1;
    }
  }
  if (!present)
  {
    return 0;
  }
  fn_803D4E0C(entry, &buffer);
  memcpy(buffer.name, entry + 0x36, 0x14);
  buffer.end = 0;
  if (fn_803D5B90(&buffer))
  {
    return entry;
  }
  return 0;
}
