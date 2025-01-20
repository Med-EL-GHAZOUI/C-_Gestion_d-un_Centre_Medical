#include<iostream>
#include<vector>
#include<string>
using namespace std;

//Classe Patient
class Patient{
  private:
	string nom;
 	int    age;
 	string historiqueMedical;
  public:
    // Constructeur
   Patient(const string& nom, int age, const string& historiqueMedical) :nom(nom), age(age), historiqueMedical(historiqueMedical) {}
   // Comparer deux patients
   bool operator==(const Patient& autre) const {
    return nom == autre.nom && age == autre.age;
   }
   // Afficher les informations du patient
   void afficherPatient() const {
      cout << "Patient: " << nom << ", Age: " << age<< ", Historique medical: " << historiqueMedical << endl;
   }
   
   string getNom() const {
    return nom;
}

};
//Classe Médecin	
class Medecin{
	private:
	  string nom;
	  string specialite;
	public:
	  // Constructeur
      Medecin(const string& nom, const string& specialite) : nom(nom), specialite(specialite) {}
      // Afficher les informations du médecin
      void afficherMedecin() const {
       cout << "Medecin: " << nom << ", Specialite: " << specialite << endl;
    }
};
//Classe Rendez vous
class RendezVous{
    private:
      Patient patient;
      Medecin medecin;
      string date;
    public:
     //Constructeur
      RendezVous(const Patient& patient, const Medecin& medecin, const string& date) : patient(patient), medecin(medecin), date(date) {}
    // Afficher les détails du rendez-vous
     virtual void afficherRendezVous() const {
        cout << "Rendez-vous standard:" << endl;
        patient.afficherPatient();
        medecin.afficherMedecin();
        cout << "Date: " << date << endl;
    }
    string getPatientName() const {
    return patient.getNom(); 
}

};
//Classe dérivée : RendezVousUrgent
class RendezVousUrgent : public RendezVous {
    private:
      int priorite;
   public:
    // Constructeur
    RendezVousUrgent(const Patient& patient, const Medecin& medecin, const string& date, int priorite) : RendezVous(patient, medecin, date), priorite(priorite) {}
    // Afficher les détails du rendez-vous urgent
    void afficherRendezVous() const override {
        cout << "Rendez-vous urgent (Priorité: " << priorite << "):" << endl;
        RendezVous::afficherRendezVous();
    }
}; 
// Classe CentreMedical
class CentreMedical {
private:
    vector<RendezVous> rendezVous;
    vector<RendezVousUrgent> rendezVousUrgents;
public:
    // Ajouter un rendez-vous standard
    void ajouterRendezVous(const RendezVous& rdv) {
        rendezVous.push_back(rdv);
    }
    // Ajouter un rendez-vous urgent
    void ajouterRendezVousUrgent(const RendezVousUrgent& rdv) {
        rendezVousUrgents.push_back(rdv);
    }
    // Afficher tous les rendez-vous
    void afficherTousLesRendezVous() const {
        if (rendezVous.empty() && rendezVousUrgents.empty()) {
            cout << "Aucun rendez-vous programme." << endl;
            return;
        }
        cout << "Liste des rendez-vous standards:" << endl;
        if (rendezVous.empty()) {
            cout << "Aucun rendez-vous standard." << endl;
        }
        else {
            for (const auto& rdv : rendezVous) {
                rdv.afficherRendezVous();
                cout << endl;
            }
        }
        cout << "Liste des rendez-vous urgents:" << endl;
        if (rendezVousUrgents.empty()) {
            cout << "Aucun rendez-vous urgent." << endl;
        }
        else {
            for (const auto& rdvUrgent : rendezVousUrgents) {
                rdvUrgent.afficherRendezVous();
                cout << endl;
            }
        }
    }
    // Rechercher les rendez-vous par patient
void rechercherRendezVousParPatient(const string& nomPatient) const {
    bool rendezVousTrouve = false;

    cout << "Rendez-vous pour le patient: " << nomPatient << endl;

    // Vérifier les rendez-vous standards
    for (const auto& rdv : rendezVous) {
        // Comparer avec le nom du patient
        if (rdv.getPatientName() == nomPatient) {
            rdv.afficherRendezVous();
            cout << endl;
            rendezVousTrouve = true;
        }
    }

    // Vérifier les rendez-vous urgents
    for (const auto& rdvUrgent : rendezVousUrgents) {
        if (rdvUrgent.getPatientName() == nomPatient) {
            rdvUrgent.afficherRendezVous();
            cout << endl;
            rendezVousTrouve = true;
        }
    }

    if (!rendezVousTrouve) {
        cout << "Aucun rendez-vous trouve pour ce patient." << endl;
    }
}
};

int main() {
	vector<Patient> patients;
	vector<Medecin> medecins;
	 int nPatients,nMedecins;
	 CentreMedical centre;
    
	//sasir les patients: 
    cout << "Combien de patients voulez-vous saisir ?"<<endl;
    cout << "le nombre de patients :";
    cin >> nPatients ;
   
    for (int i = 0; i < nPatients; i++) {
    string nom, historique;
            int age;
            cout << "\nle patient " << i <<" : " <<endl;
            cout << "Nom du patient : ";
            cin >> nom;
            cout << "Age du patient : ";
            cin >> age;
            cout << "Historique medical : ";
            cin >> historique;
            Patient patient (nom, age, historique);
            // Ajouter le patient à la liste
			patients.push_back(patient); 

            cout << "Patient ajoute : ";
            patient.afficherPatient();
     }
    
    
      cout << "\nCombien de medecins voulez-vous saisir ?"<<endl;
    cout << "le nombre de medecins :";
    cin >> nMedecins ;
    for (int i = 0; i < nMedecins; i++) {
    string nom, specialite;
            cout << "\nle medecin " << i <<" : " <<endl;
            cout << "Nom du medecin : ";
            cin >> nom;
            cout << "Specialite du medecin : ";
            cin  >>specialite;
            Medecin medecin(nom, specialite);
            medecins.push_back(medecin); 
            cout << "Medecin ajoute : ";
            medecin.afficherMedecin();
    }
     
    // Afficher tous les rendez-vous
    int nRendezVousUrgents;
    cout << "\nCombien de rendez-vous urgents voulez-vous creer ?" << endl;
    cout << "Le nombre de rendez-vous urgents : ";
    cin >> nRendezVousUrgents;

    for (int i = 0; i < nRendezVousUrgents; i++) {
        int patientIndex, medecinIndex, priorite;
        string date;
        cout << "\nSelectionner le patient (0 à " << nPatients-1 << ") : ";
        cin >> patientIndex;
        cout << "Selectionner le medecin (0 à " << nMedecins-1 << ") : ";
        cin >> medecinIndex;
        cout << "Entrez la date du rendez-vous urgent : ";
        cin >> date;
        cout << "Entrez la priorite du rendez-vous urgent : ";
        cin >> priorite;

        RendezVousUrgent rdvUrgent(patients[patientIndex], medecins[medecinIndex], date, priorite);
        centre.ajouterRendezVousUrgent(rdvUrgent);
        cout << "Rendez-vous urgent ajoute : ";
        rdvUrgent.afficherRendezVous();
    }
    
	int choix;
    do {
        cout << "\n \nMenu: " << endl;
        cout << "1. Afficher tous les patients" << endl;
        cout << "2. Afficher tous les Medecins" << endl;
        cout << "3. Comparer les patients" << endl;
        cout << "4. Afficher tous les rendez-vous" << endl; 
		cout << "5. Rechercher les rendez-vous par patient" << endl; 
        cout << "0. Quitter" << endl;
        cout << "Entrez votre choix: ";
        cin >> choix;
	switch (choix) {
		case 1: {
            cout << "\nListe des patients :" << endl;
            for (const auto& patient : patients) {
                patient.afficherPatient();
            }
            break;
        }
        case 2: {
            cout << "\nListe des medecins :" << endl;
            for (const auto& medecin : medecins) {
                medecin.afficherMedecin();
            }
            break;
        }
        case 3: {
        cout << "\n Comparaison des patients :" << std::endl;
        for (int i = 0; i < nPatients; ++i) {
        for (int j = i + 1; j < nPatients; ++j) {
            if (patients[i] == patients[j]) {
               cout << "Patient " << i + 1 << " est identique à Patient " << j + 1 << "." << endl;
            } else {
              cout << "Patient " << i + 1 << " est différent de Patient " << j + 1 << "." << endl;
              }
           }
          }
            break;
        }
        case 4:{
             centre.afficherTousLesRendezVous();       			        	
			break;         
		}
		case 5: {
    	string nomPatient;
    	cout << "\nEntrez le nom du patient pour rechercher ses rendez-vous : ";
   		 cin >> nomPatient;
   		 centre.rechercherRendezVousParPatient(nomPatient);
   	 	break;
		}
        default:{cout << "\n \t Au revoir!" << endl;
			break;
		}
            
          
    } }while (choix != 0);
    return 0;
}               