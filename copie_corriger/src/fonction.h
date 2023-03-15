#include <gtk/gtk.h>

typedef struct
{
	int jj,mm,aa;
} date;
//util.d.jj
//util.d.mm
//util.d.aa

typedef struct 
{
	char Nom[20];
	char Prenom[20];
	char User[20];
	char Pass[20];
	char Choix[20];
	char Genre[20];
	char Cin[20];
	char Vote[20];
	date d;
}util;

void ajouter(util t);
void affi_listAllUser(GtkWidget* treeviewAffiListUser,char*l);
void affi_listUser(GtkWidget* treeviewAffiListUser,char*l);
void affi_list_obs(GtkWidget* treeview2,char*l1);
void affi_list_agent(GtkWidget* treeview3,char*l2);
void affi_list_bureau(GtkWidget* treeview4,char*l3);
void supp_tree(char Cin[]);
void modi_tree(char Cin[], util o);
util chercher_util(char id []);

void TPHF();
float TPE ();


















