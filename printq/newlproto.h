 extern char *capture_stdin (void); 
 extern char *getmodesub (char *arg, int *pos); 
 extern char *gmem (int cnt, int sz); 
 extern int add_srcfile (char *path); 
 extern int attroff (int x); 
 extern int attron (int x); 
 extern int cbreak (void); 
 extern int endwin (void); 
 extern int erase (void); 
 extern int fixuppath (char *src, char *dest); 
 extern int getch (void); 
 extern int getmode (char *arg); 
 extern int getrange (char *arg, int *st, int *end); 
 extern int init_comm (void); 
 extern int init_me (void); 
 extern int init_semaphore (void); 
 extern int initpaths (void); 
 extern int initscr (void); 
 extern int ismqcode (void); 
 extern int isrunning (void); 
 extern int issocket (void); 
 extern int load_qconfig (void); 
 extern int main (int argc, char **argv); 
 extern int move (int row, int col); 
 extern int mvaddstr (int r, int c, char *s); 
 extern int noecho (void); 
 extern int parseopts (int cnt, char **v); 
 extern int queue_job (char *srcfile, char *ptr, char *form, int st, int end, int pri, int copies, char *class, int mode); 
 extern int raw (void); 
 extern int refresh (void); 
 extern int send_daemon (int type, int what, char *ptr, int size, time_t time_stamp); 
 extern int setflag (int flag, int setting); 
 extern int shut_comm (void); 
 extern int shut_sems (void); 
 extern int usage (void); 
 extern int waitready (void); 
 extern int write_d (int descriptor, char *buf, int size); 
 extern key_t myftok (char *file, char x); 
 extern void link_shutdown (void); 
 extern void make_vers_date (char *idstr, char *version, char *moddate); 
# 1 "decls.0"
