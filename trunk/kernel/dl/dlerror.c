const char *_dl_errors[] = {
  NULL,
  "Couldn't open library.",
  "Unable to resolve symbol",
  "Invaild handle."};

char *dlerror()
{
  return _dl_errors[_dl_error];
}
