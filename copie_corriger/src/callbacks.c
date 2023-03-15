#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"
#include <string.h>
#include <time.h>



void
on_ajout_compte_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *auth,*inscription;
	auth=lookup_widget(objet,"auth");
	gtk_widget_destroy(auth);
	inscription=create_inscription();
	gtk_widget_show(inscription);
}


void
on_log_clicked                         (GtkWidget      *button,
                                        gpointer         user_data)
{
	GtkWidget *lb,*username,*password,*auth,*window1,*window2,*window3,*window4,*Admin;
	char log[20];
	char Pw[20];
	int trouve=0;
	int x=-1;

	lb = lookup_widget (button,"label314");
	username = lookup_widget (button,"us");
	password = lookup_widget (button,"Pw");
	strcpy(log,gtk_entry_get_text(GTK_ENTRY(username)));
	strcpy(Pw,gtk_entry_get_text(GTK_ENTRY(password)));
	FILE *f=NULL;
	util t;
	f=fopen("utilisateur.txt","r");
	if(f!=NULL)
		{
			while(fscanf(f,"%s %s %s %s %s %s %s\n",t.Nom,t.Prenom,t.User,t.Pass,t.Choix,t.Cin)!=EOF)
			{
				if((strcmp(t.User,log)==0)&&(strcmp(t.Pass,Pw)==0))
				{
					x=1;
				}

			}
			if(x==-1)
			{
				gtk_label_set_text(GTK_LABEL(lb),"compte n'existe pas ");
			}
			else
			{
   				trouve=verif(log,Pw); 
    
			}
			fclose(f);
		}
	
	auth=lookup_widget(button,"auth");
	if(trouve==1)
	{
		gtk_widget_destroy(auth);
		Admin=create_Admin();
		gtk_widget_show(Admin);  
	} 
	
}







void
on_button1_ajout_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
	
	GtkWidget *fenetre_ath,*fenetre_insc;        
	GtkWidget *use,*nom,*prenom,*pass,*choix,*cin,*Genre,*Vote;
	GtkWidget *labelCin,*labelnom,*labelprenom,*labelpass,*labeluser,*labeltel,*jour,*mois,*an;

	labelCin=lookup_widget(objet,"label260");
	labelnom=lookup_widget(objet,"label255");
	labelprenom=lookup_widget(objet,"label256");
	labelpass=lookup_widget(objet,"label258");
	labeluser=lookup_widget(objet,"label257");
	labeltel=lookup_widget(objet,"label259");
	jour = lookup_widget (objet,"spinbutton2");
	mois = lookup_widget (objet,"spinbutton3");
	an= lookup_widget (objet,"spinbutton4");

	util t;

	
	nom = lookup_widget (objet,"nom");
	prenom = lookup_widget (objet,"prenom");
	use = lookup_widget (objet,"user");
	pass = lookup_widget (objet,"Pass");
	choix = lookup_widget (objet,"combobox33");
	Genre = lookup_widget (objet,"combobox37");
	cin = lookup_widget (objet,"cin");
	Vote = lookup_widget (objet,"combobox35");

	strcpy(t.Nom,gtk_entry_get_text(GTK_ENTRY(nom)));
	strcpy(t.Prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
	strcpy(t.User,gtk_entry_get_text(GTK_ENTRY(use)));
	strcpy(t.Pass,gtk_entry_get_text(GTK_ENTRY(pass)));
	strcpy(t.Cin,gtk_entry_get_text(GTK_ENTRY(cin)));
	t.d.jj=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
	t.d.mm=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
	t.d.aa=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(an));
	strcpy(t.Choix,gtk_combo_box_get_active_text(GTK_COMBO_BOX(choix)));
	strcpy(t.Vote,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Vote)));
	strcpy(t.Genre,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Genre)));
  
	ajouter(t);
	GtkWidget *inscription,*Admin;
	gtk_widget_destroy(inscription);
	Admin=create_Admin();
	gtk_widget_show(Admin);

}


void
on_quit_ad_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *fenetre_auth,*fenetre_admin;
	fenetre_admin=lookup_widget(button,"Admin");
	gtk_widget_destroy(fenetre_admin);
	fenetre_auth=create_auth();
	gtk_widget_show(fenetre_auth);
}

void
on_quitter1_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *fenetre_auth,*fenetre_inscription;
	fenetre_inscription=lookup_widget(button,"inscription");
	gtk_widget_destroy(fenetre_inscription);
	fenetre_auth=create_auth();
	gtk_widget_show(fenetre_auth);
}

void
on_auth_youtube_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
	system("firefox https://www.youtube.com/");
}


void
on_auth_facebook_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
	system("firefox https://www.facebook.com/");
}


void
on_auth_instagram_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
	system("firefox https://www.instagram.com/");
}


void
on_treeviewAffiListUser_row_activated  (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_buttonAffiUser_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{

	GtkWidget* p=lookup_widget(objet,"treeviewAffiListUser");
	affi_listAllUser(p,"utilisateur.txt");
}


void
on_buttonSupprimer_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
 	GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* p=lookup_widget(objet,"treeviewAffiListUser");
        gchar *Nom;      
	gchar *Prenom;
	gchar *User;
	gchar *Pass;
	gchar *Choix;
	gchar *Genre;
	gchar *Cin;
     	gchar *jj;
	gchar *mm;
	gchar *aa;
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
	//test sur la ligne selectionnée
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  
		gtk_tree_model_get (model,&iter,0,&Nom,1,&Prenom,2,&User,3,&Pass,4,&Choix,5,&Genre,6,&Cin,7,&jj,8,&mm,9,&aa,-1);
		//supprimer la ligne du treeView
           	gtk_list_store_remove(GTK_LIST_STORE(model),&iter);
		// supprimer la ligne du fichier
           	supp_tree(Cin);
	}
}


void
on_buttonValider_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *no,*pr,*ci,*us,*pass,*Role,*dd,*cin,*jour1,*mois1,*an1,*Vote1;
	util o;
	char Cin[20];

	jour1 = lookup_widget (objet_graphique,"spinbutton5");
	mois1 = lookup_widget (objet_graphique,"spinbutton6");
	an1 = lookup_widget (objet_graphique,"spinbutton7");

	o.d.jj=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour1));
	o.d.mm=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois1));
	o.d.aa=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(an1));

	dd = lookup_widget (objet_graphique,"combobox38");
	no = lookup_widget (objet_graphique,"entry1");
	pr = lookup_widget (objet_graphique,"entry2");
	Role = lookup_widget (objet_graphique,"combobox34");
	Vote1= lookup_widget (objet_graphique,"combobox36");
	cin = lookup_widget (objet_graphique,"entry5");
	us = lookup_widget (objet_graphique,"entry3");
	pass = lookup_widget (objet_graphique,"entry4");

	strcpy(o.Genre,gtk_combo_box_get_active_text(GTK_COMBO_BOX(dd)));
	strcpy(o.Vote,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Vote1)));
	strcpy(o.Nom,gtk_entry_get_text(GTK_ENTRY(no)));
	strcpy(o.Prenom,gtk_entry_get_text(GTK_ENTRY(pr)));
	strcpy(o.Choix,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Role)));
	strcpy(o.Cin,gtk_entry_get_text(GTK_ENTRY(cin)));
	strcpy(o.User,gtk_entry_get_text(GTK_ENTRY(us)));
	strcpy(o.Pass,gtk_entry_get_text(GTK_ENTRY(pass)));
	modi_tree(o.Cin,o);

	//mise a jour treeview
 	GtkWidget* p=lookup_widget(objet_graphique,"treeviewAffiListUser");
	affi_listAllUser(p,"utilisateur.txt");
}


void
on_buttonModifier_clicked              (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{ 

	GtkTreeModel     *model,*labe;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* p=lookup_widget(objet_graphique,"treeviewAffiListUser");
        gchar *Nom;
	gchar *Prenom;
	gchar *User;
	gchar *Pass;
	gchar *Choix;
	gchar *Genre;
	gchar *Cin;

        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
	//test sur la ligne selectionnée
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  
		gtk_tree_model_get (model,&iter,0,&Nom,1,&Prenom,2,&User,3,&Pass,4,&Choix,5,&Genre,6,&Cin,-1);
		// appel du donnés à partir du tableau
 		gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry1")),Nom);
 		gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry2")),Prenom);
 		gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry3")),User);
 		gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry4")),Pass);
 		gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry5")),Cin);
 		gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry6")),Genre);
	}
	//mise a jour treeview
	affi_listAllUser(p,"utilisateur.txt");
}



void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}



void
on_button7_chercher_clicked       (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
	util u;
	int test=-1;
	GtkWidget *r0, *r1;
	char Prenom[20], Nom[20], User[20],Choix[20], Genre[20],id[20] ;
	r0=lookup_widget(objet_graphique,"entry5");
	r1=lookup_widget(objet_graphique,"info"); 

	strcpy(id ,(gtk_entry_get_text(GTK_ENTRY(r0))));
 	u=chercher_util(id);
	if (strcmp(u.Cin,id)==0)
	{
		test=1;
	}
	if(test==1)
	{
		gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry1")),u.Nom);
		gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry2")),u.Prenom);
		gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry3")),u.User);
		gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry4")),u.Pass);
		gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry6")),u.Genre);
		gtk_label_set_text(GTK_LABEL(r1),"");
	}
	else
	{
		gtk_label_set_text(GTK_LABEL(r1),"l'id n'existe pas");
	}
}




void
on_Ajouter_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *fenetre_admin,*fenetre_insc;
	fenetre_admin=lookup_widget(objet,"Admin");
	gtk_widget_destroy(fenetre_admin);
	fenetre_insc=create_inscription();
	gtk_widget_show(fenetre_insc);
}


// ******************************************************** fenetre electeur *************************************************************

//ouvrir fenetre electeur
void
on_electeur_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1,*Admin;
	gtk_widget_destroy(Admin);
	window1=create_window1();
	gtk_widget_show(window1);
}


//fonction modifier
void
on_modifier_electeur_clicked           (GtkWidget      *objet,
                                        gpointer         user_data)
{
	GtkWidget *fenetre_ath,*fenetre_insc;
	GtkWidget *use,*nom,*prenom,*pass,*choix,*cin,*Genre,*Vote;
	GtkWidget *jour,*mois,*an;
	int b=1;
	jour = lookup_widget (objet,"spinbutton8");
	mois = lookup_widget (objet,"spinbutton9");
	an= lookup_widget (objet,"spinbutton10");
	util t;
	nom = lookup_widget (objet,"nom_electeur");
	prenom = lookup_widget (objet,"prenom_electeur");
	use = lookup_widget (objet,"username_electeur");
	pass = lookup_widget (objet,"pass_electeur");
	choix = lookup_widget (objet,"combobox41");
	Genre = lookup_widget (objet,"combobox39");
	cin = lookup_widget (objet,"cin_electeur");
	Vote = lookup_widget (objet,"combobox40");

	
	strcpy(t.Nom,gtk_entry_get_text(GTK_ENTRY(nom)));
	strcpy(t.Prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
	strcpy(t.User,gtk_entry_get_text(GTK_ENTRY(use)));
	strcpy(t.Pass,gtk_entry_get_text(GTK_ENTRY(pass)));
	strcpy(t.Cin,gtk_entry_get_text(GTK_ENTRY(cin)));
	t.d.jj=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
	t.d.mm=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
	t.d.aa=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(an));
	strcpy(t.Choix,gtk_combo_box_get_active_text(GTK_COMBO_BOX(choix)));
	strcpy(t.Vote,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Vote)));
	strcpy(t.Genre,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Genre)));
	modi_tree(t.Cin,t);

	//mise a jour treeview
	GtkWidget* p=lookup_widget(objet,"treeviewAffiListUser");
	affi_listUser(p,"utilisateur.txt");	
}



//fonction supprimer
void
on_supprimer_electeur_clicked          (GtkWidget      *objet,
                                        gpointer         user_data)
{
 	GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* p=lookup_widget(objet,"treeviewAffiListUser");
        
        gchar *Nom;
	gchar *Prenom;
	gchar *User;
	gchar *Pass;
	gchar *Choix;
	gchar *Genre;
	gchar *Cin;
      	gchar *jj;
	gchar *mm;
	gchar *aa;
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
	//test sur la ligne selectionnée
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  
		gtk_tree_model_get (model,&iter,0,&Nom,1,&Prenom,2,&User,3,&Pass,4,&Choix,5,&Genre,6,&Cin,7,&jj,8,&mm,9,&aa,-1);
		//supprimer la ligne du treeView
           	gtk_list_store_remove(GTK_LIST_STORE(model),&iter);
		// supprimer la ligne du fichier
            	supp_tree(Cin);
	}
}

//fonction afficher
void
on_afficher_electeur_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget* p=lookup_widget(objet,"treeviewAffiListUser");
	affi_listUser(p,"utilisateur.txt");
}


// ******************************************************** fenetre observateur ***********************************************************

//ouvrir fenetre observateur
void
on_observateur_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *window2,*Admin;
	gtk_widget_destroy(Admin);
	window2=create_window2();
	gtk_widget_show(window2);
}

//treeview observateur
void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


// fonction modifier
void
on_modifier_observateur_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{ 
	GtkWidget *fenetre_ath,*fenetre_insc;
	GtkWidget *use,*nom,*prenom,*pass,*choix,*cin,*Genre,*Vote;
	GtkWidget *jour,*mois,*an;
	int b=1;
	jour = lookup_widget (objet,"spinbutton11");
	mois = lookup_widget (objet,"spinbutton12");
	an= lookup_widget (objet,"spinbutton13");
	util t;
	nom = lookup_widget (objet,"entry11");
	prenom = lookup_widget (objet,"entry12");
	use = lookup_widget (objet,"username_observateur");
	pass = lookup_widget (objet,"pass_observateur");
	choix = lookup_widget (objet,"combobox43");
	Genre = lookup_widget (objet,"combobox42");
	cin = lookup_widget (objet,"cin_observateur");
	Vote = lookup_widget (objet,"combobox44");
	strcpy(t.Nom,gtk_entry_get_text(GTK_ENTRY(nom)));
	strcpy(t.Prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
	strcpy(t.User,gtk_entry_get_text(GTK_ENTRY(use)));
	strcpy(t.Pass,gtk_entry_get_text(GTK_ENTRY(pass)));
	strcpy(t.Cin,gtk_entry_get_text(GTK_ENTRY(cin)));
	t.d.jj=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
	t.d.mm=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
	t.d.aa=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(an));
	strcpy(t.Choix,gtk_combo_box_get_active_text(GTK_COMBO_BOX(choix)));
	strcpy(t.Vote,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Vote)));
	strcpy(t.Genre,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Genre)));
	modi_tree(t.Cin,t);
	//mise a jour treeview
	GtkWidget* p1=lookup_widget(objet,"treeview2");
	affi_list_obs(p1,"utilisateur.txt");	
}


// fonction supprimer
void
on_supprimer_observateur_clicked       (GtkWidget       *objet,
                                        gpointer         user_data)
{
 	GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* p=lookup_widget(objet,"treeview2");
        gchar *Nom;
	gchar *Prenom;
	gchar *User;
	gchar *Pass;
	gchar *Choix;
	gchar *Genre;
	gchar *Cin;
       	gchar *jj;
	gchar *mm;
	gchar *aa;
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
	//test sur la ligne selectionnée
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  
		gtk_tree_model_get (model,&iter,0,&Nom,1,&Prenom,2,&User,3,&Pass,4,&Choix,5,&Genre,6,&Cin,7,&jj,8,&mm,9,&aa,-1);
		//supprimer la ligne du treeView
           	gtk_list_store_remove(GTK_LIST_STORE(model),&iter);
		// supprimer la ligne du fichier
            	supp_tree(Cin);
	}
}


//fonction afficher
void
on_afficher_observateur_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget* p1=lookup_widget(objet,"treeview2");
	affi_list_obs(p1,"utilisateur.txt");
}



// ******************************************************** fenetre agent *************************************************************

//ouvrir fenetre agent
void
on_agent_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *window3,*Admin;
	gtk_widget_destroy(Admin);
	window3=create_window3();
	gtk_widget_show(window3);
}

// treeview agent
void
on_treeview3_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}

// fonction modifier
void
on_modifier_agent_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{ 
	GtkWidget *use2,*nom2,*prenom2,*pass2,*choix2,*cin2,*Genre2,*Vote2;
	GtkWidget *jour2,*mois2,*an2;
	int b=1;
	jour2 = lookup_widget (objet,"spinbutton14");
	mois2= lookup_widget (objet,"spinbutton15");
	an2= lookup_widget(objet,"spinbutton16");
	util t;
	nom2= lookup_widget (objet,"nom_agent");
	prenom2 = lookup_widget (objet,"entry17");
	use2 = lookup_widget (objet,"username_agent");
	pass2 = lookup_widget (objet,"pass_agent");
	choix2 = lookup_widget (objet,"combobox46");
	Genre2 = lookup_widget (objet,"combobox45");
	cin2 = lookup_widget (objet,"cin_agent");
	Vote2 = lookup_widget (objet,"combobox47");

	strcpy(t.Nom,gtk_entry_get_text(GTK_ENTRY(nom2)));
	strcpy(t.Prenom,gtk_entry_get_text(GTK_ENTRY(prenom2)));
	strcpy(t.User,gtk_entry_get_text(GTK_ENTRY(use2)));
	strcpy(t.Pass,gtk_entry_get_text(GTK_ENTRY(pass2)));
	strcpy(t.Cin,gtk_entry_get_text(GTK_ENTRY(cin2)));
	t.d.jj=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour2));
	t.d.mm=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois2));
	t.d.aa=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(an2));
	strcpy(t.Choix,gtk_combo_box_get_active_text(GTK_COMBO_BOX(choix2)));
	strcpy(t.Vote,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Vote2)));
	strcpy(t.Genre,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Genre2)));
	modi_tree(t.Cin,t);

	//mise a jour treeview
	GtkWidget* p2=lookup_widget(objet,"treeview3");
	affi_list_agent(p2,"utilisateur.txt");	
}


//fonction supprimer
void
on_supprimer_agent_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* p=lookup_widget(objet,"treeview3");
        gchar *Nom;
	gchar *Prenom;
	gchar *User;
	gchar *Pass;
	gchar *Choix;
	gchar *Genre;
	gchar *Cin;
	gchar *jj;
	gchar *mm;
	gchar *aa;
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
	//test sur la ligne selectionnée
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  
		gtk_tree_model_get (model,&iter,0,&Nom,1,&Prenom,2,&User,3,&Pass,4,&Choix,5,&Genre,6,&Cin,7,&jj,8,&mm,9,&aa,-1);
		//supprimer la ligne du treeView
           	gtk_list_store_remove(GTK_LIST_STORE(model),&iter);
		// supprimer la ligne du fichier
            	supp_tree(Cin);
	}
}

//fonction afficher
void
on_afficher_agent_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget* p2=lookup_widget(objet,"treeview3");
	affi_list_agent(p2,"utilisateur.txt");
}



// ******************************************************** fenetre bureau *************************************************************

//ouvrir fenetre bureau
void
on_bureau_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *window4,*Admin;
	gtk_widget_destroy(Admin);
	window4=create_window4();
	gtk_widget_show(window4);
}

//treeview bureau
void
on_treeview4_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}

//fonction afficher
void
on_afficher_bureau_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget* p3=lookup_widget(objet,"treeview4");
	affi_list_bureau(p3,"utilisateur.txt");
}


// ************************************************** buttons de retour ************************************************************

void
on_retour1_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *window1,*Admin;
	gtk_widget_destroy(window1);
	Admin=create_Admin();
	gtk_widget_show(Admin);
}

void
on_retour2_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *window2,*Admin;
	gtk_widget_destroy(window2);
	Admin=create_Admin();
	gtk_widget_show(Admin);
}

void
on_retour3_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *window3,*Admin;
	gtk_widget_destroy(window3);
	Admin=create_Admin();
	gtk_widget_show(Admin);
}


void
on_retour4_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *window4,*Admin;
	gtk_widget_destroy(window4);
	Admin=create_Admin();
	gtk_widget_show(Admin);
}


void
on_retour5_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *window5,*Admin;
	gtk_widget_destroy(window5);
	Admin=create_Admin();
	gtk_widget_show(Admin);
}

void
on_retour0_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *inscription,*Admin;
	gtk_widget_destroy(inscription);
	Admin=create_Admin();
	gtk_widget_show(Admin);
}


// ******************************************************** taches statistiques *************************************************************
void
on_statistiques_clicked                (GtkButton       *button,
                                        gpointer         user_data)

{ 
TPHF();
	GtkWidget *Admin,*window5;
	gtk_widget_destroy(Admin);
	window5=create_window5();
	gtk_widget_show(window5);


TPE ();	
}






