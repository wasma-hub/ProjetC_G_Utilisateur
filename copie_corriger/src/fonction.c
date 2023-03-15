#include "fonction.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>
#include "interface.h"
#include "callbacks.h"



GtkListStore *adstore;/*creation du modele de type liste*/
GtkTreeViewColumn *adcolumn;/*visualisation des colonnes*/
GtkCellRenderer *cellad;/*afficheur de cellule(text,image..)*/
FILE *f;



// ************************************************** partie authentification *********************************************************
int verif(char log[],char Pw[])
{
	int trouve=-1;
	FILE *f=NULL;
	util t;
	f=fopen("utilisateur.txt","r");
	if(f!=NULL)
	{
 		while(fscanf(f,"%s %s %s %s %s %s %s\n",t.Nom,t.Prenom,t.User,t.Pass,t.Choix,t.Cin)!=EOF)
		{
			if((strcmp(t.User,log)==0)&&(strcmp(t.Pass,Pw)==0))
			{
				if(strcmp(t.Choix,"Admin")==0)
					trouve=1;
			}

		}
		fclose(f);
	}
	return (trouve);
}





// ******************************************************** fonction ajouter *************************************************************
void ajouter(util t)
{
	FILE *f=NULL;
	f=fopen("utilisateur.txt","a");
	if(f!=NULL)
	{
    		fprintf(f,"%s %s %s %s %s %s %s %d %d %d %s \n",t.Nom,t.Prenom,t.User,t.Pass,t.Choix,t.Genre,t.Cin,t.d.jj, t.d.mm ,t.d.aa,t.Vote);
	fclose(f);
	}
}



// ******************************************************** fonction afficher *************************************************************
void affi_listAllUser(GtkWidget* treeviewAffiListUser,char*l) 
{

	char Nom[20];
	char Prenom[20];
	char User[20];
	char Pass[20];
	char Choix[20];
	char Genre[20];
	char Cin[20];
	char jj[20];
	char mm[20];
	char aa[20];
	char Vote[20];
	FILE *F;

        /* Creation du modele */
        adstore = gtk_list_store_new(11,
				     G_TYPE_STRING,
				     G_TYPE_STRING,
				     G_TYPE_STRING,			
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
				     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
				     G_TYPE_STRING
                                    		);

        /* Insertion des elements */
        F=fopen("utilisateur.txt","r");
	while(fscanf(F,"%s %s %s %s %s %s %s %s %s %s %s \n",Nom,Prenom,User,Pass,Choix,Genre,Cin,jj,mm,aa,Vote)!= EOF)

        {GtkTreeIter pIter;

         /* Creation de la nouvelle ligne */
         gtk_list_store_append(adstore, &pIter);
         /* Mise a jour des donnees */
         gtk_list_store_set(adstore, &pIter,
                            0,Nom,
                            1,Prenom,	
                            2,User,
                            3,Pass,
                            4,Choix,
                            5,Genre,
                            6,Cin,
			    7,jj,
			    8,mm,
			    9,aa,
			    10,Vote,
                            -1);}
        fclose(F);
	

	/* Creation de la 1ere colonne */

	{
	
		cellad = gtk_cell_renderer_text_new();
        	adcolumn = gtk_tree_view_column_new_with_attributes("Nom",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        	/* Ajouter la 1er colonne à la vue */
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewAffiListUser), adcolumn);


		/* Creation de la 2eme colonne */
        	cellad = gtk_cell_renderer_text_new();
        	adcolumn = gtk_tree_view_column_new_with_attributes("Prenom",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
		/* Ajouter la 2emme colonne à la vue */
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewAffiListUser), adcolumn);

		/* Creation de la 3eme colonne */
        	cellad = gtk_cell_renderer_text_new();
        	adcolumn = gtk_tree_view_column_new_with_attributes("User",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
		/* Ajouter la 3emme colonne à la vue */
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewAffiListUser), adcolumn);
       

       		/* Creation de la 4eme colonne */
        	cellad = gtk_cell_renderer_text_new();
        	adcolumn = gtk_tree_view_column_new_with_attributes("password",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
		/* Ajouter la 4emme colonne à la vue */
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewAffiListUser), adcolumn);


            	/* Creation de la 5eme colonne */
        	cellad = gtk_cell_renderer_text_new();
        	adcolumn = gtk_tree_view_column_new_with_attributes("choix",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
		/* Ajouter la 5emme colonne à la vue */
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewAffiListUser), adcolumn);



           	/* Creation de la 6eme colonne */
        	cellad = gtk_cell_renderer_text_new();
        	adcolumn = gtk_tree_view_column_new_with_attributes("Genre",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);
		/* Ajouter la 6emme colonne à la vue */
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewAffiListUser), adcolumn);

		/* Creation de la 7eme colonne */
        	cellad = gtk_cell_renderer_text_new();
        	adcolumn = gtk_tree_view_column_new_with_attributes("Cin",
                                                            cellad,
                                                            "text", 6,
                                                            NULL);
		/* Ajouter la 7emme colonne à la vue */
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewAffiListUser), adcolumn);

		/* Creation de la 8eme colonne */
        	cellad = gtk_cell_renderer_text_new();
       		adcolumn = gtk_tree_view_column_new_with_attributes("jj",
                                                            cellad,
                                                            "text", 7,
                                                            NULL);
		/* Ajouter la 8emme colonne à la vue */
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewAffiListUser), adcolumn);

		/* Creation de la 9eme colonne */
        	cellad = gtk_cell_renderer_text_new();
        	adcolumn = gtk_tree_view_column_new_with_attributes("mm",
                                                            cellad,
                                                            "text", 8,
                                                            NULL);

		/* Ajouter la 9emme colonne à la vue */
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewAffiListUser), adcolumn);

		/* Creation de la 10eme colonne */
        	cellad = gtk_cell_renderer_text_new();
        	adcolumn = gtk_tree_view_column_new_with_attributes("aa",
                                                            cellad,
                                                            "text", 9,
                                                            NULL);

		/* Ajouter la 10emme colonne à la vue */
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewAffiListUser), adcolumn);
		/* Creation de la 10eme colonne */
        	cellad = gtk_cell_renderer_text_new();
        	adcolumn = gtk_tree_view_column_new_with_attributes("Vote",
                                                            cellad,
                                                            "text", 10,
                                                            NULL);

		/* Ajouter la 10emme colonne à la vue */
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewAffiListUser), adcolumn);

	}
	
 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeviewAffiListUser),
                                  GTK_TREE_MODEL(adstore)  );   //afficher treeview

}



void affi_listUser(GtkWidget* treeviewAffiListUser,char*l)
{

	char Nom[20];
	char Prenom[20];
	char User[20];
	char Pass[20];
	char Choix[20];
	char Genre[20];
	char Cin[20];
	char jj[20];
	char mm[20];
	char aa[20];
	char Vote[20];
	FILE *F,*FW;
  	util t;
  
	F = fopen ("utilisateur.txt", "r");
	FW = fopen ("tr.txt", "w");

  	if ((F!=NULL)&&(FW!=NULL))
 	{
  		while (fscanf (F,"%s %s %s %s %s %s %s %s %s %s %s\n",t.Nom,t.Prenom,t.User,t.Pass,t.Choix,t.Genre,t.Cin,jj,mm,aa,t.Vote) != EOF)
    			if (strcmp(t.Choix,"Electeur") == 0)
      				fprintf (FW,"%s %s %s %s %s %s %s %s %s %s %s\n",t.Nom,t.Prenom,t.User,t.Pass,t.Choix,t.Genre,t.Cin,jj,mm,aa,t.Vote);
  	fclose (F);
  	fclose (FW);
}

        /* Creation du modele */
        adstore = gtk_list_store_new(11,
				     G_TYPE_STRING,
				     G_TYPE_STRING,
				     G_TYPE_STRING,			
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
				     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
				     G_TYPE_STRING
                                    		);

        /* Insertion des elements */
        F=fopen("tr.txt","r");
	while(fscanf(F,"%s %s %s %s %s %s %s %s %s %s %s \n",Nom,Prenom,User,Pass,Choix,Genre,Cin,jj,mm,aa,Vote)!= EOF)

        {GtkTreeIter pIter;

         /* Creation de la nouvelle ligne */
         gtk_list_store_append(adstore, &pIter);
         /* Mise a jour des donnees */
         gtk_list_store_set(adstore, &pIter,
                            0,Nom,
                            1,Prenom,	
                            2,User,
                            3,Pass,
                            4,Choix,
                            5,Genre,
                            6,Cin,
			    7,jj,
			    8,mm,
			    9,aa,
			    10,Vote,
                            -1);}
        fclose(F);
	

	/* Creation de la 1ere colonne */

	{
	
	cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Nom",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        /* Ajouter la 1er colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewAffiListUser), adcolumn);


	/* Creation de la 2eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Prenom",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	/* Ajouter la 2emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewAffiListUser), adcolumn);

	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("User",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewAffiListUser), adcolumn);
       

       	/* Creation de la 4eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("password",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	/* Ajouter la 4emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewAffiListUser), adcolumn);


            /* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("choix",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewAffiListUser), adcolumn);



        /* Creation de la 6eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Genre",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);
	/* Ajouter la 6emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewAffiListUser), adcolumn);

	/* Creation de la 7eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Cin",
                                                            cellad,
                                                            "text", 6,
                                                            NULL);
	/* Ajouter la 7emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewAffiListUser), adcolumn);

	/* Creation de la 8eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("jj",
                                                            cellad,
                                                            "text", 7,
                                                            NULL);
	/* Ajouter la 8emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewAffiListUser), adcolumn);

	/* Creation de la 9eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("mm",
                                                            cellad,
                                                            "text", 8,
                                                            NULL);

	/* Ajouter la 9emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewAffiListUser), adcolumn);

	/* Creation de la 10eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("aa",
                                                            cellad,
                                                            "text", 9,
                                                            NULL);

	/* Ajouter la 10emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewAffiListUser), adcolumn);
	
	/* Creation de la 11eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Vote",
                                                            cellad,
                                                            "text", 10,
                                                            NULL);

	/* Ajouter la 11emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewAffiListUser), adcolumn);

	}
	
 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeviewAffiListUser),
                                  GTK_TREE_MODEL(adstore)  );

}



void affi_list_obs(GtkWidget* treeview2,char*l1)
{

	char Nom[20];
	char Prenom[20];
	char User[20];
	char Pass[20];
	char Choix[20];
	char Genre[20];
	char Cin[20];
	char jj[20];
	char mm[20];
	char aa[20];
	char Vote[20];
	FILE *F,*FW;
  	util t;
  
	F = fopen ("utilisateur.txt", "r");
	FW = fopen ("tr1.txt", "w");

  	if ((F!=NULL)&&(FW!=NULL))
 	{
  		while (fscanf (F,"%s %s %s %s %s %s %s %s %s %s %s\n",t.Nom,t.Prenom,t.User,t.Pass,t.Choix,t.Genre,t.Cin,jj,mm,aa,Vote) != EOF)
    		if (strcmp(t.Choix,"Observateur") == 0)
      fprintf (FW,"%s %s %s %s %s %s %s %s %s %s %s\n",t.Nom,t.Prenom,t.User,t.Pass,t.Choix,t.Genre,t.Cin,jj,mm,aa,Vote);
  	fclose (F);
  	fclose (FW);

}

        /* Creation du modele */
        adstore = gtk_list_store_new(11,
				     G_TYPE_STRING,
				     G_TYPE_STRING,
				     G_TYPE_STRING,			
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
				     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
				     G_TYPE_STRING
                                    		);

        /* Insertion des elements */
        F=fopen("tr1.txt","r");
	while(fscanf(F,"%s %s %s %s %s %s %s %s %s %s %s \n",Nom,Prenom,User,Pass,Choix,Genre,Cin,jj,mm,aa,Vote)!= EOF)

        {GtkTreeIter pIter;

         /* Creation de la nouvelle ligne */
         gtk_list_store_append(adstore, &pIter);
         /* Mise a jour des donnees */
         gtk_list_store_set(adstore, &pIter,
                            0,Nom,
                            1,Prenom,	
                            2,User,
                            3,Pass,
                            4,Choix,
                            5,Genre,
                            6,Cin,
			    7,jj,
			    8,mm,
			    9,aa,
			    10,Vote,
                            -1);}
        fclose(F);
	

	/* Creation de la 1ere colonne */

	{
	
	cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Nom",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        /* Ajouter la 1er colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview2), adcolumn);


	/* Creation de la 2eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Prenom",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	/* Ajouter la 2emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview2), adcolumn);

	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("User",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview2), adcolumn);
       

       	/* Creation de la 4eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("password",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	/* Ajouter la 4emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview2), adcolumn);


        /* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("choix",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview2), adcolumn);



        /* Creation de la 6eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Genre",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);
	/* Ajouter la 6emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview2), adcolumn);

	/* Creation de la 7eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Cin",
                                                            cellad,
                                                            "text", 6,
                                                            NULL);
	/* Ajouter la 7emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview2), adcolumn);

	/* Creation de la 8eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("jj",
                                                            cellad,
                                                            "text", 7,
                                                            NULL);
	/* Ajouter la 8emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview2), adcolumn);

	/* Creation de la 9eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("mm",
                                                            cellad,
                                                            "text", 8,
                                                            NULL);

	/* Ajouter la 9emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview2), adcolumn);

	/* Creation de la 10eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("aa",
                                                            cellad,
                                                            "text", 9,
                                                            NULL);

	/* Ajouter la 10emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview2), adcolumn);
	
	/* Creation de la 11eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Vote",
                                                            cellad,
                                                            "text", 10,
                                                            NULL);

	/* Ajouter la 11emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview2), adcolumn);

	}
	
 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview2),
                                  GTK_TREE_MODEL(adstore)  );

}


void affi_list_agent(GtkWidget* treeview3,char*l2)
{
	char Nom[20];
	char Prenom[20];
	char User[20];
	char Pass[20];
	char Choix[20];
	char Genre[20];
	char Cin[20];
	char jj[20];
	char mm[20];
	char aa[20];
	char Vote[20];
 	FILE *F,*FW;
  	util t;
  
	F = fopen ("utilisateur.txt", "r");
	FW = fopen ("tr2.txt", "w");

  	if ((F!=NULL)&&(FW!=NULL))
 	{
  		while (fscanf (F,"%s %s %s %s %s %s %s %s %s %s %s\n",t.Nom,t.Prenom,t.User,t.Pass,t.Choix,t.Genre,t.Cin,jj,mm,aa,Vote) != EOF)
    			if (strcmp(t.Choix,"Agent") == 0)
      				fprintf (FW,"%s %s %s %s %s %s %s %s %s %s %s\n",t.Nom,t.Prenom,t.User,t.Pass,t.Choix,t.Genre,t.Cin,jj,mm,aa,Vote);
  	fclose (F);
  	fclose (FW);

}

        /* Creation du modele */
        adstore = gtk_list_store_new(11,
				     G_TYPE_STRING,
				     G_TYPE_STRING,
				     G_TYPE_STRING,			
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
				     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
				     G_TYPE_STRING
                                    		);

        /* Insertion des elements */
        F=fopen("tr2.txt","r");
	while(fscanf(F,"%s %s %s %s %s %s %s %s %s %s %s \n",Nom,Prenom,User,Pass,Choix,Genre,Cin,jj,mm,aa,Vote)!= EOF)

        {GtkTreeIter pIter;

         /* Creation de la nouvelle ligne */
         gtk_list_store_append(adstore, &pIter);
         /* Mise a jour des donnees */
         gtk_list_store_set(adstore, &pIter,
                            0,Nom,
                            1,Prenom,	
                            2,User,
                            3,Pass,
                            4,Choix,
                            5,Genre,
                            6,Cin,
			    7,jj,
			    8,mm,
			    9,aa,
			    10,Vote,
                            -1);}
        fclose(F);
	

	/* Creation de la 1ere colonne */

	{
	
	cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Nom",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        /* Ajouter la 1er colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview3), adcolumn);


	/* Creation de la 2eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Prenom",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	/* Ajouter la 2emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview3), adcolumn);

	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("User",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview3), adcolumn);
       

       	/* Creation de la 4eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("password",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	/* Ajouter la 4emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview3), adcolumn);


        /* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("choix",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview3), adcolumn);



        /* Creation de la 6eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Genre",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);
	/* Ajouter la 6emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview3), adcolumn);

	/* Creation de la 7eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Cin",
                                                            cellad,
                                                            "text", 6,
                                                            NULL);
	/* Ajouter la 7emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview3), adcolumn);

	/* Creation de la 8eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("jj",
                                                            cellad,
                                                            "text", 7,
                                                            NULL);
	/* Ajouter la 8emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview3), adcolumn);

	/* Creation de la 9eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("mm",
                                                            cellad,
                                                            "text", 8,
                                                            NULL);

	/* Ajouter la 9emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview3), adcolumn);

	/* Creation de la 10eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("aa",
                                                            cellad,
                                                            "text", 9,
                                                            NULL);

	/* Ajouter la 10emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview3), adcolumn);
	
	/* Creation de la 11eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Vote",
                                                            cellad,
                                                            "text", 10,
                                                            NULL);

	/* Ajouter la 11emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview3), adcolumn);

	}
	
 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview3),
                                  GTK_TREE_MODEL(adstore)  );
}



void affi_list_bureau(GtkWidget* treeview4,char*l3)
{
	char Nom[20];
	char Prenom[20];
	char User[20];
	char Pass[20];
	char Choix[20];
	char Genre[20];
	char Cin[20];
	char jj[20];
	char mm[20];
	char aa[20];
	char Vote[20];
 	FILE *F,*FW;
  	util t;
  
	F = fopen ("utilisateur.txt", "r");
	FW = fopen ("tr3.txt", "w");

  	if ((F!=NULL)&&(FW!=NULL))
 	{
  		while (fscanf (F,"%s %s %s %s %s %s %s %s %s %s %s\n",t.Nom,t.Prenom,t.User,t.Pass,t.Choix,t.Genre,t.Cin,jj,mm,aa,t.Vote) != EOF)
    		if (strcmp(t.Choix,"Bureau") == 0)
      fprintf (FW,"%s %s %s %s %s %s %s %s %s %s %s\n",t.Nom,t.Prenom,t.User,t.Pass,t.Choix,t.Genre,t.Cin,jj,mm,aa,t.Vote);
  	fclose (F);
  	fclose (FW);
}

        /* Creation du modele */
        adstore = gtk_list_store_new(10,
				     G_TYPE_STRING,
				     G_TYPE_STRING,
				     G_TYPE_STRING,			
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
				     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
				     G_TYPE_STRING
                                    		);

        /* Insertion des elements */
        F=fopen("tr3.txt","r");
	while(fscanf(F,"%s %s %s %s %s %s %s %s %s %s %s \n",Nom,Prenom,User,Pass,Choix,Genre,Cin,jj,mm,aa,Vote)!= EOF)

        {GtkTreeIter pIter;

        /* Creation de la nouvelle ligne */
         gtk_list_store_append(adstore, &pIter);
       	/* Mise a jour des donnees */
         gtk_list_store_set(adstore, &pIter,
                            0,Nom,
                            1,Prenom,	
                            2,User,
                            3,Pass,
                            4,Choix,
                            5,Genre,
                            6,Cin,
			    7,jj,
			    8,mm,
			    9,aa,
			    10,Vote,
                            -1);}
        fclose(F);
	

	/* Creation de la 1ere colonne */

	{
	
	cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Nom",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        /* Ajouter la 1er colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview4), adcolumn);


	/* Creation de la 2eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Prenom",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	/* Ajouter la 2emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview4), adcolumn);

	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("User",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview4), adcolumn);
       

       	/* Creation de la 4eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("password",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	/* Ajouter la 4emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview4), adcolumn);


        /* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("choix",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview4), adcolumn);



        /* Creation de la 6eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Genre",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);
	/* Ajouter la 6emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview4), adcolumn);

	/* Creation de la 7eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Cin",
                                                            cellad,
                                                            "text", 6,
                                                            NULL);
	/* Ajouter la 7emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview4), adcolumn);

	/* Creation de la 8eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("jj",
                                                            cellad,
                                                            "text", 7,
                                                            NULL);
	/* Ajouter la 8emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview4), adcolumn);

	/* Creation de la 9eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("mm",
                                                            cellad,
                                                            "text", 8,
                                                            NULL);

	/* Ajouter la 9emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview4), adcolumn);

	/* Creation de la 10eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("aa",
                                                            cellad,
                                                            "text", 9,
                                                            NULL);

	/* Ajouter la 10emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview4), adcolumn);

	/* Creation de la 11eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Vote",
                                                            cellad,
                                                            "text", 10,
                                                            NULL);

	/* Ajouter la 11emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview4), adcolumn);


	}
	
 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview4),
                                  GTK_TREE_MODEL(adstore)  );

}





// ******************************************************** fonction supprimer ***********************************************************
void supp_tree(char Cin[])
{

	FILE *F,*FW;
	util t;
	F = fopen ("utilisateur.txt", "r");
	FW = fopen ("trsupp.txt", "w");

  	if ((F!=NULL)&&(FW!=NULL))
 	{
  		while (fscanf (F,"%s %s %s %s %s %s %s %d %d %d %s\n",t.Nom,t.Prenom,t.User,t.Pass,t.Choix,t.Genre,t.Cin,&t.d.jj,&t.d.mm,&t.d.aa,t.Vote) != EOF)
    			if (strcmp (t.Cin,Cin) != 0)
      				fprintf (FW,"%s %s %s %s %s %s %s %d %d %d %s\n",t.Nom,t.Prenom,t.User,t.Pass,t.Choix,t.Genre,t.Cin,t.d.jj,t.d.mm,t.d.aa,t.Vote);
  		fclose (F);
  		fclose (FW);
		remove("utilisateur.txt");
		rename("trsupp.txt", "utilisateur.txt");
	}
}




util chercher_util(char id[])
{
	util q, o;
	FILE *f;
	f=fopen("utilisateur.txt","r");
	if(f!=NULL)
	{
		while(fscanf(f,"%s %s %s %s %s %s %s %s \n",q.Nom,q.Prenom,q.User,q.Pass,q.Choix,q.Genre,q.Cin,q.Vote)!=EOF)
	
		if(strcmp(q.Cin,id)==0){
		return q;
	}
	else
	{
       		strcpy(o.Nom,"xxx");
        	strcpy(o.Prenom,"xxx");
        	strcpy(o.User,"xxx");
		strcpy(o.Pass,"xxx");
		strcpy(o.Choix,"xxx");
		strcpy(o.Genre,"xxx");
		return o ;
	}
	fclose(f);
}
}




// ******************************************************** fonction modifier *************************************************************
void modi_tree(char Cin[] , util o)
{
  	util t;
   	FILE *F, *FW;
	F = fopen ("utilisateur.txt", "r");
	FW = fopen ("trmodi.txt", "w");
 	if ((F!=NULL)&&(FW!=NULL))
 	{
  		while (fscanf (F, "%s %s %s %s %s %s %s %d %d %d %s\n",t.Nom,t.Prenom,t.User,t.Pass,t.Choix,t.Genre,t.Cin,&t.d.jj,&t.d.mm,&t.d.aa,t.Vote) != EOF)
    			if (strcmp (t.Cin,Cin) == 0)
     			{
				fprintf(FW, "%s %s %s %s %s %s %s %d %d %d %.3s\n",o.Nom,o.Prenom,o.User,o.Pass,o.Choix,o.Genre,t.Cin,o.d.jj,o.d.mm,o.d.aa,o.Vote);
     			}
     			else
     			{
      				fprintf(FW, "%s %s %s %s %s %s %s %d %d %d %.3s\n",t.Nom,t.Prenom,t.User,t.Pass,t.Choix,t.Genre,t.Cin,t.d.jj,t.d.mm,t.d.aa,t.Vote);
    			}
     
  		fclose (F);
  		fclose (FW);
		remove("utilisateur.txt");
		rename("trmodi.txt", "utilisateur.txt");

	}

}


//****************************************************** statistiques *************************************************************

void TPHF()
{
	float tphf;
	int fe=0;
	int ho=0;
	int vote=1;
	float hov; // taux de participation de homme voté 
	float fev; // taux de participation de femme votée
	util t;
	remove("stat.txt");
	FILE *f=fopen("utilisateur.txt","r");
	FILE *f2=fopen("stat.txt","a");
	if (f!=NULL)
	{
		while (fscanf(f,"%s %s %s %s %s %s %s %d %d %d %s\n",t.Nom,t.Prenom,t.User,t.Pass,t.Choix,t.Genre,t.Cin,&t.d.jj,&t.d.mm,&t.d.aa,t.Vote) != EOF)
		{ 
			if(strcmp(t.Genre,"Femme")==0 && strcmp(t.Vote,"Oui")==0 )
				{fe++;}
			if (strcmp(t.Genre,"Homme")==0 && strcmp(t.Vote,"Oui")==0)
				{ho++;}

		}
	 	vote = fe +ho ;
		hov=(float) ho/vote;
		fev=(float) fe/vote;
	
	fprintf(f2,"%d %d %d %f %f",fe,ho,vote,hov,fev);
	}
	fclose(f);
	fclose(f2);

}

float TPE ()
{	
	float tpe;
	int se=0;
	int vote=0;
	util t;
	remove("stat.txt");
	FILE *f=fopen("utilisateur.txt","r");
	FILE *f2=fopen("stat.txt","a");
	if (f!=NULL)
	{

		while (fscanf(f,"%s %s %s %s %s %s %s %d %d %d %s\n",t.Nom,t.Prenom,t.User,t.Pass,t.Choix,t.Genre,t.Cin,&t.d.jj,&t.d.mm,&t.d.aa,t.Vote) != EOF)
		{ 
			if(strcmp(t.Choix,"Electeur")==0)
			  	{se++;}
			
			if (strcmp(t.Choix,"Electeur")==0 && strcmp(t.Vote,"Oui")==0)
				{vote++;}
		}
			tpe=(float) vote/se;
	fprintf(f2,"%d %d %f",se,vote,tpe);
	}
	fclose(f);
	return tpe;
}


