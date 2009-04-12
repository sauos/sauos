int _dl_error = 0;
void *dlopen(const char *f, int fl){_dl_error = 1; return;}
void *dlsym(void *h, const char *s){_dl_error = 2; return 0x80000000;}
int dlclose(void *h){h = (void*)NULL; return;}
