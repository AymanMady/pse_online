#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

int main() {
	// Initialise le g�n�rateur de nombres al�atoires avec la graine actuelle du temps
    srand(time(0));
	int nbr_elm = 10;
	int nbr_lignes = 10;
	fstream file("fichier_ecrire.txt",ios::out|ios::trunc);
	if(file.is_open()){
		
		for(int i=0;i<nbr_lignes;i++){
			for(int i=0;i<nbr_lignes;i++){


		    // G�n�re un entier al�atoire entre 1 et 30000
		    int nombreAleatoire = rand() % 30000 + 1;
			file<<nombreAleatoire<<":";
	
			}	
			
			file<<endl;
		}
	
		file.close();
		cout<<"Fichier creer et donnees enregistrer";
	}
	else{
		cout<<"Erreur d'enrgistrement";
	}
    return 0;
}

