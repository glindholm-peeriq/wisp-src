 extern char *approx_size (struct q_item *qi); 
 extern char *c_username (int uid); 
 extern char *fmtpitem (char *data, int row, int col); 
 extern char *fmtqitem (char *data, int row, int col); 
 extern char *getshseg (int size, int key); 
 extern char *gmem (int cnt, int sz); 
 extern char *repstr (char ch, int cnt); 
 extern char *showfield (char *buf, int bufsz, int wpos, int wsize, char *showbuf); 
 extern char *str_td (void); 
 extern char *str_u (void); 
 extern char *time12 (int hour, int min); 
 extern int addpitem (struct p_item *ptr); 
 extern int addqitem (struct q_item *ptr); 
 extern int attroff (int x); 
 extern int attron (int x); 
 extern int candelete (char *path); 
 extern int candisp (void); 
 extern int cangobot (void); 
 extern int cangodn (void); 
 extern int cangotop (void); 
 extern int cangoup (void); 
 extern int catch (void); 
 extern int cbreak (void); 
 extern int chop_printers_old (void); 
 extern int chop_queue_old (void); 
 extern int clearstatusl (void); 
 extern int cmpqitems (char **pi1, char **pi2); 
 extern int delremconfirm (char *type); 
 extern int doalign (struct p_item *p); 
 extern int dobot (void); 
 extern int dochgfrm (struct p_item *p); 
 extern int doclrerr (struct p_item *p); 
 extern int dodel (struct q_item *q); 
 extern int dodisp (struct q_item *q); 
 extern int dodn (void); 
 extern int doedit (char *x); 
 extern int doendis (struct p_item *p); 
 extern int doholdrel (struct q_item *q); 
 extern int dopdn (void); 
 extern int dopup (void); 
 extern int dorem (struct q_item *q); 
 extern int dostopstart (struct q_item *q); 
 extern int dotop (void); 
 extern int doup (void); 
 extern int endwin (void); 
 extern int erase (void); 
 extern int findprinter (struct p_item **d1, struct p_item **d2); 
 extern int findqueueitem (struct q_item **d1, struct q_item **d2); 
 extern int fixuppath (char *src, char *dest); 
 extern int get_bool (int *pval, int size, int row, int col, int dummy); 
 extern int get_disp (int *pval, int size, int row, int col, int dummy); 
 extern int get_int (int *pval, int field_width, int row, int col, int max); 
 extern int get_string (char *string, int wsize, int row, int col, int max); 
 extern int getch (void); 
 extern int getipckey (char *path, char *type, unsigned char mod); 
 extern int has_changed (int type); 
 extern int ilpmanage (void); 
 extern int ilpwisp (void); 
 extern int in_screen (char *data); 
 extern int init_comm (void); 
 extern int init_me (void); 
 extern int init_semaphore (void); 
 extern int init_shmem (void); 
 extern int initpaths (void); 
 extern int initscr (void); 
 extern int ismqcode (void); 
 extern int isoperator (int id); 
 extern int isrunning (void); 
 extern int issocket (void); 
 extern int load_items (void); 
 extern int load_pdump (void); 
 extern int load_qconfig (void); 
 extern int load_qdump (void); 
 extern int main (int argc, char **argv); 
 extern int move (int row, int col); 
 extern int mvaddcen (int line, char *str); 
 extern int mvaddstr (int r, int c, char *s); 
 extern int noecho (void); 
 extern int notedit (void); 
 extern int process_input (char *data); 
 extern int prterrp (void); 
 extern int prtr_changed (void); 
 extern int queue_changed (void); 
 extern int raw (void); 
 extern int refresh (void); 
 extern int save_pos (void); 
 extern int send_daemon (int type, int what, char *ptr, int size, time_t time_stamp); 
 extern int setflag (int flag, int setting); 
 extern int shalign (void); 
 extern int show_fkeys (void); 
 extern int show_item (char *ptr); 
 extern int show_list (void); 
 extern int show_pstatus (void); 
 extern int show_td (void); 
 extern int shut_comm (void); 
 extern int shut_sems (void); 
 extern int shut_shmem (void); 
 extern int statusl (char *p); 
 extern int stopedit (char *x); 
 extern int tag_printers_old (void); 
 extern int tag_queue_old (void); 
 extern int togglemode (void); 
 extern int toggleshow (void); 
 extern int wait_input (void); 
 extern int waitready (void); 
 extern int write_d (int descriptor, char *buf, int size); 
 extern key_t myftok (char *file, char x); 
 extern time_t filetime (char *path); 
 extern void graceful_exit (void); 
 extern void license_warning (void); 
 extern void link_shutdown (void); 
 extern void make_vers_date (char *idstr, char *version, char *moddate); 
 extern void truncspc (char *p); 
 static char *center (char *mess); 
 static int wwaitpid (int pid, int *rc); 
# 1 "decls.0"
