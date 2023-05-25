class Vehicle:
    def __init__(self, marque, modele, annee, couleur):
        self.marque = marque
        self.modele = modele
        self.annee = annee
        self.couleur = couleur
    
    def afficher_details(self):
        print(f"Marque: {self.marque}")
        print(f"Modèle: {self.modele}")
        print(f"Année: {self.annee}")
        print(f"Couleur: {self.couleur}")


class TrafficStatistics:
    def __init__(self):
        self.vehicles = []
    
    def ajouter_vehicule(self, marque, modele, annee, couleur):
        vehicle = Vehicle(marque, modele, annee, couleur)
        self.vehicles.append(vehicle)
    
    def supprimer_vehicule(self, marque, modele):
        for vehicle in self.vehicles:
            if vehicle.marque == marque and vehicle.modele == modele:
                self.vehicles.remove(vehicle)
                break
    
    def modifier_vehicule(self, marque, modele, annee=None, couleur=None):
        for vehicle in self.vehicles:
            if vehicle.marque == marque and vehicle.modele == modele:
                if annee:
                    vehicle.annee = annee
                if couleur:
                    vehicle.couleur = couleur
                break
    
    def afficher_statistiques(self, critere=None, valeur=None):
        count = 0
        for vehicle in self.vehicles:
            if critere and valeur:
                if getattr(vehicle, critere) == valeur:
                    count += 1
            else:
                count += 1
                vehicle.afficher_details()
        print(f"Nombre de véhicules: {count}")
    
    def rechercher_vehicule(self, critere, valeur):
        for vehicle in self.vehicles:
            if getattr(vehicle, critere) == valeur:
                vehicle.afficher_details()


# Exemple d'utilisation de l'application

app = TrafficStatistics()

# Ajout de véhicules
app.ajouter_vehicule("Toyota", "Corolla", 2019, "Rouge")
app.ajouter_vehicule("Honda", "Civic", 2020, "Bleu")
app.ajouter_vehicule("Kawasaki", "Ninja", 2021, "Noir")

# Affichage de la liste complète des véhicules
app.afficher_statistiques()

# Affichage des statistiques pour les véhicules rouges
app.afficher_statistiques("couleur", "Rouge")

# Recherche d'un véhicule par marque
app.rechercher_vehicule("marque", "Toyota")

# Modification d'un véhicule
app.modifier_vehicule("Honda", "Civic", couleur="Vert")

# Suppression d'un véhicule
app.supprimer_vehicule("Kawasaki", "Ninja")

# Affichage des statistiques mises à jour
app.afficher_statistiques()


