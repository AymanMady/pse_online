#include <iostream>
#include <time.h>
#include <stdlib.h>
#include<fstream>
#include<string>

#include <ctime>
using namespace std;

void creerUnficher(long n, string const nomFich) {

	ofstream flux(nomFich.c_str());

	if(flux) {
		long i;
		srand(time(NULL));

		for(i=1; i<n; i++) {
			int e = rand()%10000;
			flux <<e<<":";
		}
		flux <<rand()%10000<<endl;
	} else {
		cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
	}


}
// Lire un fichier dans un tableau
long lireFichier(long tab[], char * nomF) {

	fstream fich;
	string  element;
	fich.open(nomF);
	long i=0;

	while(getline(fich,element,':')) {
		const char * els = element.c_str();
		tab[i++] = atoi(els);

	}
	fich.close();
	return i;
}

void triSelection(long tab[], long n){
	long i, j, tmp, index;
 
  for (i=0; i < (n-1); i++)
  {
    index = i;
   
    for (j=i + 1; j < n; j++)
    {
      if (tab[index] > tab[j])
        index = j;
    }
    if (index != i)
    {
      tmp = tab[i];
      tab[i] = tab[index];
      tab[index] = tmp;
    }
  }
}

void fusion(long t[],long debut1, long fin1, long fin2);
void triFusion(long t[],long debut, long fin) {
	if(fin-debut > 0 ) {
		int milieu = (debut+ fin) / 2;
		triFusion(t, debut, milieu);     //trier la moitié gauche récursivement
		triFusion(t,milieu + 1, fin); //trier la moitié droite récursivement
		fusion(t, debut, milieu, fin);
	}
}
void fusion(long t[],long debut1, long fin1, long fin2) {
	int i = debut1;
	int j = fin1+1;
	int k=0;
	int temp[fin2-debut1+1];
	while(i<=fin1 && j<= fin2) {
		if (t[i] < t[j]) {
			temp[k++] = t[i];
			i++;
		} else {
			temp[k++] = t[j];
			j++;
		}
	}
	while(i<=fin1) {
		temp[k++] = t[i++];
	}
	while(j<=fin2) {
		temp[k++] = t[j++];
	}

	for(k = 0; k <= fin2-debut1; k++) {
		t[k+debut1] = temp[k];
	}

}







int main() {
	/*
	int  n, i, t[1000];

	cout<<" Entrez le nombre d'éléments : ";
	cin>>n;

	//cout<<" Entrez "<<n<<" entiers : ";

	srand(time(NULL));


	for (i = 0; i < n; i++)
	t[i] = rand()%n;
	//cin>>t[i];

	cout<<" le tableau afant le tri : \n ";
	for(i = 0; i < n; i++)  {
	 cout<<t[i] <<"  ";
	}
	cout<<"  \n";
	triFusion(t,0, n-1);

	cout<<" le tableau trié : \n";
	for(i = 0; i < n; i++)  {
	 cout<<t[i] <<"  ";
	}
	cout<<endl;
	*/
	
	
	
	creerUnficher(60000,"tri3.txt");
	cout<<" debut tri d'un fichier \n";
	long  t[60000];
	long n = lireFichier(t,"tri3.txt");
	cout<<" nombre de valeur dans le fichier = "<<n<<endl;
	
	cout<<"  \n";
	double time_spent = 0.0;
 	
 	
 	


//            tri par fusion
	clock_t start_time = clock();

	triFusion(t,0, n-1);
 

	clock_t end_time = clock();


	double temp_fusion = double(end_time - start_time) / CLOCKS_PER_SEC * 1000;


			
			
//				tri par selection
				
	start_time = clock();

	triSelection(t,n);


	end_time = clock();


	double temp_selection = double(end_time - start_time) / CLOCKS_PER_SEC * 1000;



//	long i;
////	cout<<" le tableau trié : \n";
////	for(i = 0; i < n; i++)  {
////		cout<<t[i] <<"  ";
////	}
//	cout<<endl;
	cout<<" le temps de tri par slection : \n"<<temp_selection<<" Ms"<<endl;
	cout<<" le temps de tri par fusion : \n"<<temp_fusion<<" Ms"<<endl;

	return 0;
}
