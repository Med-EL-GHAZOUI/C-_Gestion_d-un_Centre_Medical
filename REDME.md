# Gestion d'un Centre Médical

## I. Introduction

### 1. Contexte général

Le projet présenté vise à développer un système de gestion de rendez-vous médicaux. Ce système permet de gérer les patients, les médecins, et leurs rendez-vous, en prenant en compte les spécificités des rendez-vous urgents. L'objectif est de créer une interface simple permettant aux utilisateurs d'ajouter, afficher et comparer des patients, des médecins, et des rendez-vous, tout en gérant une priorité pour les rendez-vous urgents.

### 2. Présentation de l'utilité principale du projet

Le système de gestion des rendez-vous facilite l'organisation des consultations médicales. Il permet de programmer, visualiser et gérer les rendez-vous tout en optimisant les priorités des patients dans le cadre des consultations urgentes.

### 3. Objectifs du projet

L'objectif principal est de créer un système de gestion médical capable de :

- Ajouter des patients et des médecins.
- Créer des rendez-vous, y compris urgents, avec des priorités.
- Comparer les patients entre eux.
- Afficher l’ensemble des informations de manière structurée et lisible.

### 4. Technologies utilisées

Le projet est implémenté en C++ et utilise les bibliothèques suivantes :

- iostream pour la gestion des entrées/sorties.
- vector pour gérer les collections de patients, médecins, et rendez-vous.
- string pour manipuler les chaînes de caractères.

### 5. Conclusion

Ce projet a permis de créer une solution simple et efficace pour gérer les rendez-vous médicaux. En intégrant des fonctionnalités comme la gestion des urgences et la comparaison des patients, il offre une base solide pour d'éventuelles améliorations futures.

## II. Analyse des besoins

### 1. Introduction

Cette section présente les exigences fonctionnelles et non fonctionnelles du projet. Les exigences fonctionnelles concernent les actions que le système doit être capable de réaliser, comme l'ajout de patients et de médecins, la gestion des rendez-vous et la comparaison de patients. Les exigences non fonctionnelles abordent des aspects comme la performance et la facilité d’utilisation du système.

### 2. Exigences fonctionnelles

Le système doit être capable de :

- Ajouter des informations sur les patients (nom, âge, historique médical) et les médecins (nom, spécialité).
- Permettre de créer des rendez-vous associés à un patient et un médecin, avec une date spécifique.
- Permettre de gérer des rendez-vous urgents, incluant une priorité.
- Comparer deux patients pour vérifier s’ils ont les mêmes informations.
- Afficher les informations des patients, médecins, et rendez-vous.

### 3. Exigences non fonctionnelles

- Facilité d’utilisation : L’interface est en ligne de commande, donc simple à utiliser avec des menus clairs.
- Performance : Le système doit être capable de gérer un nombre raisonnable de patients et de médecins sans ralentir.
- Maintenabilité : Le code est écrit de manière à être facilement modifiable pour intégrer de nouvelles fonctionnalités ou améliorer les performances.

### 4. Conclusion

Les exigences ont été clairement définies, permettant de concevoir un système répondant aux besoins des utilisateurs. Le respect de ces exigences garantit que le système sera utile et efficace tout en restant simple à utiliser.

## III. Conception du système

### 1. Introduction

Dans cette partie, nous décrivons la conception du système en présentant les classes principales, leurs attributs et leurs méthodes. Nous abordons également la modélisation du système, avec une présentation des relations entre les classes et des choix de conception, comme la surcharge des opérateurs pour comparer les patients.

### 2. Modélisation des classes et objets

Le système repose sur plusieurs classes pour représenter les entités principales :

#### 2.1. Classe Patient :

- Attributs : nom, âge, historique médical.
- Méthodes : un constructeur pour l’initialisation, une méthode pour afficher les informations du patient.

#### 2.2. Classe Medecin :

- Attributs : nom, spécialité.
- Méthodes : un constructeur pour l'initialisation, une méthode pour afficher les informations du médecin.

#### 2.3. Classe RendezVous :

- Attributs : patient, médecin, date du rendez-vous.
- Méthodes : un constructeur pour l'initialisation, une méthode pour afficher les informations du rendez-vous.

#### 2.4. Classe RendezVousUrgent (hérite de RendezVous) :

- Attributs : priorité (ajoutée pour spécifier la priorité d’un rendez-vous urgent).
- Méthodes : surcharge de la méthode afficherRendezVous pour inclure la priorité.

#### 2.5. Classe CentreMedical :

- Attributs : listes de rendez-vous standards et urgents.
- Méthodes : ajout de rendez-vous, affichage des rendez-vous.

### 3. Diagramme UML

Un diagramme UML pourrait représenter les relations suivantes entre les classes :

- Patient et Medecin sont liés à RendezVous via une association.
- RendezVousUrgent hérite de RendezVous, avec l'ajout de la priorité.
- CentreMedical contient des listes de RendezVous et RendezVousUrgent.

### 4. Surcharge des opérateurs

- Opérateur == sur la classe Patient pour comparer les patients par nom et âge.

### 5. Conclusion

La conception du système repose sur une structure claire et modulaire, permettant une gestion efficace des patients, médecins et rendez-vous. La surcharge d'opérateurs et l'héritage dans les classes permettent une manipulation fluide des données.

## IV. Détails d'implémentation

### 1. Introduction

Cette section détaille l'implémentation du système, en fournissant des extraits de code et en expliquant le choix des structures de données et des méthodes. Nous mettons également en lumière les défis techniques rencontrés lors du développement et comment ils ont été résolus.

### 2. Code source

Voici quelques parties du code pour illustrer l'implémentation :

#### Classe Patient

```cpp
class Patient {
private:
    string nom;
    int age;
    string historiqueMedical;

public:
    Patient(const string& nom, int age, const string& historiqueMedical)
        : nom(nom), age(age), historiqueMedical(historiqueMedical) {}

    bool operator==(const Patient& autre) const {
        return nom == autre.nom && age == autre.age;
    }

    void afficherPatient() const {
        cout << "Patient: " << nom << ", Age: " << age << ", Historique médical: " << historiqueMedical << endl;
    }

    string getNom() const {
        return nom;
    }
};
### Classe Medecin

 class Medecin {
private:
    string nom;
    string specialite;

public:
    Medecin(const string& nom, const string& specialite)
        : nom(nom), specialite(specialite) {}

    void afficherMedecin() const {
        cout << "Médecin: " << nom << ", Spécialité: " << specialite << endl;
    }
};

### Classe RendezVous
class RendezVous {
private:
    Patient patient;
    Medecin medecin;
    string date;

public:
    RendezVous(const Patient& patient, const Medecin& medecin, const string& date)
        : patient(patient), medecin(medecin), date(date) {}

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

### Classe RendezVousUrgent
class RendezVousUrgent : public RendezVous {
private:
    int priorite;

public:
    RendezVousUrgent(const Patient& patient, const Medecin& medecin, const string& date, int priorite)
        : RendezVous(patient, medecin, date), priorite(priorite) {}

    void afficherRendezVous() const override {
        cout << "Rendez-vous urgent (Priorité: " << priorite << "):" << endl;
        RendezVous::afficherRendezVous();
    }
};

### Classe CentreMedical
class CentreMedical {
private:
    vector<RendezVous> rendezVous;
    vector<RendezVousUrgent> rendezVousUrgents;

public:
    void ajouterRendezVous(const RendezVous& rdv) {
        rendezVous.push_back(rdv);
    }

    void ajouterRendezVousUrgent(const RendezVousUrgent& rdv) {
        rendezVousUrgents.push_back(rdv);
    }

    void afficherTousLesRendezVous() const {
        if (rendezVous.empty() && rendezVousUrgents.empty()) {
            cout << "Aucun rendez-vous programmé." << endl;
            return;
        }

        cout << "Liste des rendez-vous standards:" << endl;
        if (rendezVous.empty()) {
            cout << "Aucun rendez-vous standard." << endl;
        } else {
            for (const auto& rdv : rendezVous) {
                rdv.afficherRendezVous();
                cout << endl;
            }
        }

        cout << "Liste des rendez-vous urgents:" << endl;
        if (rendezVousUrgents.empty()) {
            cout << "Aucun rendez-vous urgent." << endl;
        } else {
            for (const auto& rdvUrgent : rendezVousUrgents) {
                rdvUrgent.afficherRendezVous();
                cout << endl;
            }
        }
    }

    void rechercherRendezVousParPatient(const string& nomPatient) const {
        bool rendezVousTrouve = false;

        cout << "Rendez-vous pour le patient: " << nomPatient << endl;

        for (const auto& rdv : rendezVous) {
            if (rdv.getPatientName() == nomPatient) {
                rdv.afficherRendezVous();
                cout << endl;
                rendezVousTrouve = true;
            }
        }

        for (const auto& rdvUrgent : rendezVousUrgents) {
            if (rdvUrgent.getPatientName() == nomPatient) {
                rdvUrgent.afficherRendezVous();
                cout << endl;
                rendezVousTrouve = true;
            }
        }

        if (!rendezVousTrouve) {
            cout << "Aucun rendez-vous trouvé pour ce patient." << endl;
        }
    }
};
3. Description de l'implémentation
Le système gère deux types de rendez-vous : standards et urgents.
Les rendez-vous urgents sont traités via une classe dérivée, permettant d'ajouter une priorité spécifique.
Les données sont gérées par des vecteurs pour stocker les patients, médecins et rendez-vous.
4. Défis rencontrés et solutions apportées
Gestion des rendez-vous urgents : La solution consiste à créer une classe dérivée de RendezVous pour ajouter un attribut de priorité.
Comparaison des patients : L'utilisation de l'opérateur == permet de simplifier la comparaison des patients sur la base de certains attributs.
5. Conclusion
L'implémentation a permis de réaliser un système fonctionnel et modulaire, utilisant les structures de données appropriées pour gérer les patients, médecins et rendez-vous. Les défis techniques ont été résolus de manière élégante, assurant ainsi la robustesse du code.

V. Tests et validation
1. Introduction
Les tests sont essentiels pour s'assurer que le système fonctionne correctement. Cette section décrit les scénarios de test utilisés pour valider les différentes fonctionnalités du système, comme l'ajout de rendez-vous, la comparaison des patients et l'affichage des informations.

2. Scénarios de test
Ajout de patients et de médecins : Vérifier que les patients et les médecins sont correctement ajoutés et affichés.
Création de rendez-vous urgents : Vérifier que les rendez-vous urgents sont correctement ajoutés, avec la priorité et les bonnes informations.
Comparaison de patients : Tester la méthode de comparaison pour s'assurer que les patients identiques sont correctement identifiés.
3. Résultats des tests
Les tests montrent que toutes les fonctionnalités (ajout, affichage, comparaison) fonctionnent comme prévu.
Les rendez-vous urgents sont affichés avec la priorité correcte.
4. Conclusion
Les tests ont confirmé que le système fonctionne comme prévu, avec toutes les fonctionnalités (ajout de patients, gestion des rendez-vous, etc.) opérationnelles. Aucune erreur majeure n'a été rencontrée, et le système répond aux attentes définies dans les exigences.

VI. Conclusion & Perspectives
1. Bilan du projet
Le projet a été un succès, permettant de gérer efficacement les informations des patients, médecins, et rendez-vous, y compris les urgents. Il respecte les exigences fonctionnelles et non fonctionnelles définies au début.

2. Limites du projet
Le projet manque de persistance des données (les informations ne sont pas sauvegardées après l'exécution). De plus, l'interface est uniquement en ligne de commande, ce qui peut limiter l'ergonomie pour l'utilisateur.
3. Perspectives d'amélioration
Ajouter une interface graphique pour faciliter l'utilisation.
Utiliser une base de données pour stocker les informations de manière persistante.
Ajouter des fonctionnalités comme la gestion des annulations de rendez-vous et des notifications.
VII. Annexes
1. Code source complet
Le code source complet est disponible dans les fichiers du projet.

2. Exécuter le code
Pour exécuter le code, compilez les fichiers source avec un compilateur C++ et lancez l'exécutable généré.
```
